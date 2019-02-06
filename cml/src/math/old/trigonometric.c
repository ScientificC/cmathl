#include <stdlib.h>
#undef CML_NO_ALIASES
#define CML_NO_ALIASES
#include <cml/math.h>

#ifdef CML_NO_MATH
long double
__cml_atan(long double value, int n_max)
{
        long double sign = 1.0L;
        long double x = value;
        long double y = 0.0L;

        (void) n_max;

        if (cml_isnull(value))
        {
                return 0.0L;
        }
        else if (x < 0.0L)
        {
                sign = (-1.0L);
                x *= (-1.0L);
        }

        x = (x-1.0L)/(x+1.0L);
        y = x*x;
        x = ((((((((.0028662257L*y - .0161657367L)*y + .0429096138L)*y -
                  .0752896400L)*y + .1065626393L)*y - .1420889944L)*y +
               .1999355085L)*y - .3333314528L)*y + 1)*x;
        x = .785398163397L + sign*x;

        return x;
}

#else
        #include <math.h>
        #define __cml_atan(x, ...) __CML_MATH_NAME(atan)(x)
#endif

/*
 * Computes real arc cosine
 *
 * @param double x
 * @return double
 */

double
cml_acos(double x)
{
        double y;

        y = cml_asin(x);

        return M_PI_2 - y;
}


/*
 * Computes real arc sine
 * --| asin(x) = atan(x / sqrt(1 − x²))
 *
 * @param double x
 * @return double
 */

double
cml_asin(double x)
{
        double y, z, w, k;

        y = x*x;
        z = 1.0 - y;
        w = cml_sqrt(z);
        k = x/w;

        return cml_atan(k);
}


/*
 * Computes real arc tangent
 *
 * @param double x
 * @return double
 */

double
cml_atan(double x)
{
        double s, a;

        a = cml_abs(x);
        s = cml_sgn(x);

        return s * (double) __cml_atan(a, 33);
}


/*
 * Computes real arc tangent, using signs to determinate cuadrants
 * --| atan2(y, x) = M_PI_2*sgn(y) - atan(x/y)
 *
 * @param double y
 * @param double x
 * @return double
 */

double
cml_atan2(double y, double x)
{
        double s, k, j, z;

        s = cml_sgn(y);
        k = x/y;
        j = cml_atan(k);
        z = M_PI_2 * s;

        return z - j;
}


/*
 * Computes real cotangent
 *
 * @param double x
 * @return double
 */

double
cml_cot(double x)
{
        double y;

        y = cml_sin(x);

        if (cml_isnull(y))
        {
                return cml_nan();
        }

        return cml_cos(x) / y;
}


/*
 * Computes real cosecant
 *
 * @param double x
 * @return double
 */

double
cml_csc(double x)
{
        double y;

        y = cml_sin(x);
        return cml_inverse(y);
}


/*
 * Computes real secant function by using trigonometric identities
 *
 * @param double x
 * @return double
 */

double
cml_sec(double x)
{
        double y;

        y = cml_cos(x);
        return cml_inverse(y);
}

/*
 * Computes real tangent
 * --| tan(x) = sin(x) / cos(x)
 *
 * @param double x
 * @return double
 */

double
cml_tan(double x)
{
        double y;

        y = cml_cos(x);

        if (cml_isnull(y))
        {
                return cml_nan();
        }

        return cml_sin(x) / y;
}
