#include <stdlib.h>
#include <scic/errno.h>
#include <cml/math.h>

/**
 * Circular cosine
 * 
 * Range reduction is into intervals of pi/4. The reduction
 * error is nearly eliminated by contriving an extended precision
 * modular arithmetic.
 *
 * Two polynomial approximating functions are employed:
 * 
 * Between 0 and pi/4 the cosine is approximated by
 *      1  -  x**2 Q(x**2).
 * 
 * Between pi/4 and pi/2 the sine is represented as
 *      x  +  x**3 P(x**2).
 * 
 */

extern double cml_polevl(double, void *, int);
extern double p1evl(double, void *, int);

static double sincof[] = {
        1.58962301576546568060E-10,
        -2.50507477628578072866E-8,
        2.75573136213857245213E-6,
        -1.98412698295895385996E-4,
        8.33333333332211858878E-3,
        -1.66666666666666307295E-1,
};

static double coscof[6] = {
        -1.13585365213876817300E-11,
        2.08757008419747316778E-9,
        -2.75573141792967388112E-7,
        2.48015872888517045348E-5,
        -1.38888888888730564116E-3,
        4.16666666666665929218E-2,
};

static double DP1 =   7.85398125648498535156E-1;
static double DP2 =   3.77489470793079817668E-8;
static double DP3 =   2.69515142907905952645E-15;

static double lossth = 1.073741824e9;

double
cml_cos(double x)
{
        double y, z, zz;
        long i;
        int j, sign;

        if (cml_isnan(x))
	        return x;

        if (!cml_isfinite(x))
	{
                SCIC_ERROR_VAL("cos", SCIC_EDOM, CML_NAN);
	}

        /* make argument positive */
        sign = 1;

        if (x < 0.0)
	{
	        x = -x;
	}

        if (x > lossth)
        {
                SCIC_ERROR_VAL("cos", SCIC_ELOSS, 0.0);
        }

        y = cml_floor(x/M_PI_4); /* integer part of x/M_PI_4 */

        /* strip high bits of integer part to prevent integer overflow */
        z = cml_ldexp(y, -4.0);
        z = cml_floor(z);           /* integer part of y/8 */
        z = y - cml_ldexp(z, 4.0);  /* y - 16 * (y/16) */

        i = z; /* convert to integer for tests on the phase angle */

        /* map zeros to origin */
        if (i & 1)
        {
                i += 1;
                y += 1.0;
        }
        
        j = i & 07; /* octant modulo 360 degrees */
        
        /* reflect in x axis */
        if (j > 3)
        {
                sign = -sign;
                j -= 4;
        }

        if (j > 1)
	        sign = -sign;

        /* Extended precision modular arithmetic */
        z = ((x - y * DP1) - y * DP2) - y * DP3;

        zz = z * z;

        if ((j == 1) || (j == 2))
        {
                y = z + z * z * z * cml_polevl(zz, sincof, 5);
        }
        else
        {
                y = 1.0 - cml_ldexp(zz, -1.0) + zz * zz * cml_polevl(zz, coscof, 5);
        }

        if (sign < 0)
                y = -y;

        return y;
}
