#include <stdlib.h>
#include <cml.h>


/*
 * Computes real power function developed by using the exponentiation process
 * --| pow(x, n) = sgn(x)e^(nlog(|x|))
 *
 * @param real_t x
 * @param real_t n
 * @return real_t pow(x, n)
 */

real_t
real_pow(real_t x, real_t n)
{
        /* Domain check */
        if (real_is_null(x)) {
                return real_is_null(n) ?
                       real_nan() :
                       x;
        }

        /* Declaration of variables and structures */
        real_t s, y, z, w, k, h;

        /* Mathematical algorithm */
        s = real_sgn(x);
        y = real_abs(x);
        z = real_log(y);
        w = real_prod(n, z);
        k = real_exp(w);
        h = real_prod(s, k);

        /* Return */
        return h;
}


/**
 * Computes real root function by using the exponentiation process
 *
 * @param real_t x
 * @param real_t n: exponent
 * @return real_t
 */

real_t
real_root(real_t x, real_t n)
{
        /* Declaration of variables and structures */
        real_t y, z;

        /* Mathematical algorithm */
        y = real_div(1.0, n);
        z = real_pow(x, y);

        /* Return */
        return z;
}


/**
 * Computes real square root function developed by using the exponentiation process
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_sqrt(real_t x)
{
        return real_root(x, 2.0);
}
