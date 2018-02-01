#include <stdlib.h>
#include <cml.h>

/*
 * Returns e raised to the given power
 *
 * @param real_t x: Exponent of the function
 * @return real_t
 */

real_t
real_exp(real_t x)
{
        /* Declaration of variables and structures */
        mint_t i;
        cml_math_t ai, ex;

        /* Mathematical algorithm */
        ai = 1.0;
        ex = ai;

        for (i = 1; i < CML_SERIES_TOP_IT_L; ++i) {
                ai = ai*(x)/i;
                ex = ex + ai;
        }

        /* Return */
        return (real_t) ex;
}


/*
 * The logarithm logb(x) can be computed from the logarithms of x and b with
 * respect to an arbitrary base k using the following formula,
 * --| log_b(x) = log_k(x) / log_k(b)
 *
 * @param real_t x
 * @param real_t b
 * @return real_t
 */

real_t
real_log_b(real_t x, real_t b)
{
        /* Declaration of variables and structures */
        real_t y, z, w;

        /* Mathematical algorithm */
        y = real_log(x);
        z = real_log(b);
        w = real_div(y, z);

        /* Return */
        return w;

}


/*
 * Computes real natural logarithm function by using hyperbolic definition
 * --| log(x) = arctanh((x^2 - 1)/(x^2 + 1))
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_log(real_t x)
{
        /* Domain check */
        if (x <= 0) {
                return real_nan();
        }

        /* Declaration of variables and structures */
        real_t y, z, w, k, h;

        /* Mathematical algorithm */
        y = real_prod(x, x);
        z = y - 1.0;
        w = y + 1.0;
        k = real_div(z, w);
        h = real_atanh(k);

        /* Return */
        return h;

}
