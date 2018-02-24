#include <stdlib.h>
#include <cml/math.h>

/*
 * Computes absolute value of a floating point value
 *
 * @param double x
 * @return double
 */

double
cml_abs(double x)
{
        /* Declaration of variables and structures */
        double sgn, y;

        /* Mathematical algorithm */
        sgn = cml_sgn(x);
        y = cml_mul(x, sgn);

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
cml_add(double x, double y)
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
cml_ared_a(double x, double a)
{
        /* Declaration of variables and structures */
        double z, k, w;

        /* Mathematical algorithm */
        z = cml_div_e(x, a);
        k = cml_mul(z, a);
        w = cml_sub(x, k);

        /* Return */
        return w;
}

double
cml_ared(double x)
{
        /* Declaration of variables and structures */
        double z, k, w;

        /* Mathematical algorithm */
        z = cml_div_e(x, M_TAU);
        k = cml_mul(z, M_TAU);
        w = cml_sub(x, k);

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
cml_div_e(double x, double y)
{
        /* Declaration of variables and structures */
        double z, w;

        /* Mathematical algorithm */
        z = cml_div(x, y);
        w = cml_floor(z);

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
cml_div(double x, double y)
{
        return x / y;
}


double
cml_hypot(double x, double y)
{
        return cml_sqrt(x*x + y*y);
}


double
cml_inverse(double x)
{
        /* Declaration of variables and structures */
        double h;

        /* Mathematical algorithm */
        h = cml_isnull(x) ?
            cml_nan() :
            cml_div(1.0, x);

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
cml_mod(double x, double y)
{
        /* Declaration of variables and structures */
        double z, w, k;

        /* Mathematical algorithm */
        z = cml_div_e(x, y);
        w = cml_mul(y, z);
        k = cml_sub(x, w);

        /* Return */
        return k;
}


double
cml_opposite(double x)
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
cml_mul(double x, double y)
{
        return x * y;
}


double
cml_sgn(double x)
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
cml_sub(double x, double y)
{
        return x - y;
}
