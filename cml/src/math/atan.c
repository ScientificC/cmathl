#include <stdlib.h>
#include <scic/errno.h>
#include <cml/math.h>


extern double cml_polevl(double, void *, int);
extern double cml_p1evl(double, void *, int);

#define MOREBITS 6.123233995736765886130E-17

/* arctan(x)  = x + x^3 P(x^2)/Q(x^2)
   0 <= x <= 0.66
   Peak relative error = 2.6e-18  */

static double P[5] = {
        -8.750608600031904122785E-1,
        -1.615753718733365076637E1,
        -7.500855792314704667340E1,
        -1.228866684490136173410E2,
        -6.485021904942025371773E1,
};

static double Q[5] = {
        /* 1.000000000000000000000E0, */
        2.485846490142306297962E1,
        1.650270098316988542046E2,
        4.328810604912902668951E2,
        4.853903996359136964868E2,
        1.945506571482613964425E2,
};

/* tan(3*pi/8) */
static double T3P8 = 2.41421356237309504880;

/**
 * Inverse circular tangent
 *      (arctangent)
 * 
 * Returns radian angle between -pi/2 and +pi/2 whose tangent
 * is x.
 *
 * Range reduction is from three intervals into the interval
 * from zero to 0.66.  The approximant uses a rational
 * function of degree 4/5 of the form x + x**3 P(x)/Q(x).
 * 
 */

double
cml_atan(double x)
{
        double y, z;
        short sign, flag;

        if (x == 0.0)
                return x;

        if (x == CML_POSINF)
                return M_PI_2;
        if (x == CML_NEGINF)
                return -M_PI_2;

        /* make argument positive and save the sign */
        sign = 1;

        if (x < 0.0)
        {
                sign = -1;
                x = -x;
        }

        /* range reduction */
        flag = 0;

        if (x > T3P8)
        {
                y = M_PI_2;
                flag = 1;
                x = -(1.0/x);
        }
        else if (x <= 0.66)
        {
                y = 0.0;
        }
        else
        {
                y = M_PI_4;
                flag = 2;
                x = (x - 1.0) / (x + 1.0);
        }

        z = x * x;
        z = z * cml_polevl(z, P, 4) / cml_p1evl(z, Q, 5);
        z = x * z + x;

        if (flag == 2)
                z += 0.5 * MOREBITS;
        else if (flag == 1)
                z += MOREBITS;
        
        y = y + z;
        
        if (sign < 0)
                y = -y;

        return y;
}


/**
 * Computes real arc tangent, using signs to determinate cuadrants
 * --| atan2(y, x) = M_PI_2*sgn(y) - atan(x/y)
 * 
 * Quadrant correct inverse circular tangent
 * 
 * Returns radian angle whose tangent is y/x.
 * TODO: Define compile time symbol ANSIC = 1 for ANSI standard,
 * range -PI < z <= +PI, args (y,x); else ANSIC = 0 for range
 * 0 to 2PI, args (x,y).
 *
 * @param double y
 * @param double x
 * @return double
 */

__CML_EXTERN_INLINE double
cml_atan2(double y, double x)
{
        return M_PI_2 * cml_sgn(y) - cml_atan(x / y);
}