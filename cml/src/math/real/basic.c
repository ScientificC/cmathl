#include <stdlib.h>
#include <cml.h>

/*
 * Computes absolute value of a floating point value
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_abs(real_t x)
{
        /* Declaration of variables and structures */
        real_t sgn, y;

        /* Mathematical algorithm */
        sgn = real_sgn(x);
        y = real_mul(x, sgn);

        /* Return */
        return y;
}


/*
 * Computes real add
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_add(real_t x, real_t y)
{
        return x + y;
}


/*
 * An angle x is reduced to the interval [0, 2pi] by subtracting a number k of
 * 2pi radians, where k is the integer division between x and 2pi
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_ared(real_t x)
{
        /* Declaration of variables and structures */
        real_t z, k, w;

        /* Mathematical algorithm */
        z = real_div_e(x, (TWOPI));
        k = real_mul(z, (TWOPI));
        w = real_sub(x, k);

        /* Return */
        return w;
}


/*
 * Computes the quotient and remainder of integer division
 *
 * @param real_t x
 * @param real_t y
 * @return real_t
 */

real_t
real_div_e(real_t x, real_t y)
{
        /* Declaration of variables and structures */
        real_t z, w;

        /* Mathematical algorithm */
        z = real_div(x, y);
        w = real_floor(z);

        /* Return */
        return w;
}


/*
 * Computes real division
 *
 * @param real_t x
 * @param real_t y
 * @return real_t
 */

real_t
real_div(real_t x, real_t y)
{
        return x / y;
}


real_t
real_inverse(real_t x)
{
        /* Declaration of variables and structures */
        real_t h;

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
 * @param real_t x
 * @param real_t y
 * @return real_t
 */

real_t
real_mod(real_t x, real_t y)
{
        /* Declaration of variables and structures */
        real_t z, w, k;

        /* Mathematical algorithm */
        z = real_div_e(x, y);
        w = real_mul(y, z);
        k = real_sub(x, w);

        /* Return */
        return k;
}


real_t
real_opposite(real_t x)
{
        return (real_t) -x;
}


/*
 * Computes real product
 *
 * @param real_t x
 * @param real_t y
 * @return real_t
 */

real_t
real_mul(real_t x, real_t y)
{
        return x * y;
}


real_t
real_sgn(real_t x)
{
        return (real_t) (x >= 0.0 ? 1.0 : -1.0);
}


/*
 * Computes real substraction
 *
 * @param real_t x
 * @param real_t y
 * @return real_t
 */

real_t
real_sub(real_t x, real_t y)
{
        return x - y;
}
