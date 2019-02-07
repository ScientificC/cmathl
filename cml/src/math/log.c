#include <stdlib.h>
#include <scic/errno.h>
#include <cml/math.h>

/**
 * Natural logarithm
 * 
 * the development of this function was inspired by the definitions
 * present in https://github.com/jeremybarnes/cephes
 * 
 * Returns the base e (2.718...) logarithm of x.
 *
 * The argument is separated into its exponent and fractional
 * parts.  If the exponent is between -1 and +1, the logarithm
 * of the fraction is approximated by
 *
 *     log(1+x) = x - 0.5 x**2 + x**3 P(x)/Q(x).
 *
 * Otherwise, setting  z = 2(x-1)/x+1),
 * 
 *     log(x) = z + z**3 P(z)/Q(z).
 * 
 */

extern double cml_polevl(double, void *, int);
extern double cml_p1evl(double, void *, int);

#define SQRTH 0.70710678118654752440

static double P[] = {
        1.01875663804580931796E-4,
        4.97494994976747001425E-1,
        4.70579119878881725854E0,
        1.44989225341610930846E1,
        1.79368678507819816313E1,
        7.70838733755885391666E0,
};

static double Q[] = {
        /* 1.00000000000000000000E0, */
        1.12873587189167450590E1,
        4.52279145837532221105E1,
        8.29875266912776603211E1,
        7.11544750618563894466E1,
        2.31251620126765340583E1,
};


/* Coefficients for log(x) = z + z**3 P(z)/Q(z),
 * where z = 2(x-1)/(x+1)
 * 1/sqrt(2) <= x < sqrt(2)
 */

static double R[3] = {
        -7.89580278884799154124E-1,
        1.63866645699558079767E1,
        -6.41409952958715622951E1,
};

static double S[3] = {
        /* 1.00000000000000000000E0,*/
        -3.56722798256324312549E1,
        3.12093766372244180303E2,
        -7.69691943550460008604E2,
};

double
cml_log(double x)
{
        int e;
        double y, z;

        if (cml_isnan(x))
                return x;

        if (x == CML_POSINF)
                return x;

        /* Test for domain */
        if (x <= 0.0)
        {
                if (x == 0.0)
                {
                        SCIC_ERROR_VAL("log", SCIC_ESING, CML_NEGINF);

                }
                else
                {
                        SCIC_ERROR_VAL("log", SCIC_EDOM, CML_NAN);
                }
        }

        /* Equivalent C language standard library function: */
        x = cml_frexp(x, &e);

        /* logarithm using log(x) = z + z**3 P(z)/Q(z),
        * where z = 2(x-1)/x+1)
        */

        if ((e > 2) || (e < -2))
        {
                if (x < SQRTH)
                { /* 2(2x - 1) / (2x + 1) */
                        e -= 1;
                        z = x - 0.5;
                        y = 0.5 * z + 0.5;
                }
                else
                { /* 2(x - 1) / (x + 1)   */
                        z = x - 0.5;
                        z -= 0.5;
                        y = 0.5 * x  + 0.5;
                }

                x = z / y;

                /* rational form */
                z = x * x;
                z = x * (z * cml_polevl(z, R, 2) / cml_p1evl(z, S, 3));
                y = e;
                z = z - y * 2.121944400546905827679e-4;
                z = z + x;
                z = z + e * 0.693359375;

                return z;
        }

        /* logarithm using log(1+x) = x - .5x**2 + x**3 P(x)/Q(x) */

        if (x < SQRTH)
        {
                e -= 1;
                x = cml_ldexp(x, 1) - 1.0; /*  2x - 1  */
        }	
        else
        {
                x = x - 1.0;
        }

        /* rational form */
        z = x*x;

        y = x * (z * cml_polevl(x, P, 5) / cml_p1evl(x, Q, 5));

        if (e) y = y - e * 2.121944400546905827679e-4;
        
        y = y - cml_ldexp(z, -1);   /*  y - 0.5 * z  */
        z = x + y;
        
        if (e) z = z + e * 0.693359375;

        return z;
}