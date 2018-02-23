#include <stdlib.h>
#include <cml.h>

/*
 * Computes absolute value of a floating point value
 *
 * @param double x
 * @return double
 */

double
real_abs(double x)
{
        /* Declaration of variables and structures */
        double sgn, y;

        /* Mathematical algorithm */
        sgn = real_sgn(x);
        y = real_mul(x, sgn);

        /* Return */
        return y;
}


/*
 * Computes real add
 *
 * @param double x
 * @return double
 */

double
real_add(double x, double y)
{
        return x + y;
}


/*
 * An angle x is reduced to the interval [0, 2pi] by subtracting a number k of
 * 2pi radians, where k is the integer division between x and 2pi
 *
 * @param double x
 * @return double
 */

double
real_ared_a(double x, double a)
{
        /* Declaration of variables and structures */
        double z, k, w;

        /* Mathematical algorithm */
        z = real_div_e(x, a);
        k = real_mul(z, a);
        w = real_sub(x, k);

        /* Return */
        return w;
}

double
real_ared(double x)
{
        /* Declaration of variables and structures */
        double z, k, w;

        /* Mathematical algorithm */
        z = real_div_e(x, M_TAU);
        k = real_mul(z, M_TAU);
        w = real_sub(x, k);

        /* Return */
        return w;
}


/*
 * Computes the quotient and remainder of integer division
 *
 * @param double x
 * @param double y
 * @return double
 */

double
real_div_e(double x, double y)
{
        /* Declaration of variables and structures */
        double z, w;

        /* Mathematical algorithm */
        z = real_div(x, y);
        w = real_floor(z);

        /* Return */
        return w;
}


/*
 * Computes real division
 *
 * @param double x
 * @param double y
 * @return double
 */

double
real_div(double x, double y)
{
        return x / y;
}


double
real_hypot(double x, double y)
{
        return real_sqrt(x*x + y*y);
}


double
real_inverse(double x)
{
        /* Declaration of variables and structures */
        double h;

        /* Mathematical algorithm */
        h = real_isnull(x) ?
            real_nan() :
            real_div(1.0, x);

        /* Return */
        return h;
}


/*
 * remainder of the floating point division operation
 *
 * @param double x
 * @param double y
 * @return double
 */

double
real_mod(double x, double y)
{
        /* Declaration of variables and structures */
        double z, w, k;

        /* Mathematical algorithm */
        z = real_div_e(x, y);
        w = real_mul(y, z);
        k = real_sub(x, w);

        /* Return */
        return k;
}


double
real_opposite(double x)
{
        return (double) -x;
}


/*
 * Computes real product
 *
 * @param double x
 * @param double y
 * @return double
 */

double
real_mul(double x, double y)
{
        return x * y;
}


double
real_sgn(double x)
{
        return (double) (x >= 0.0 ? 1.0 : -1.0);
}


/*
 * Computes real substraction
 *
 * @param double x
 * @param double y
 * @return double
 */

double
real_sub(double x, double y)
{
        return x - y;
}
