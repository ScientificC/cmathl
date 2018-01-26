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
                       NAN :
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
