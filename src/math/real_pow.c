#include <stdlib.h>
#include <cml.h>

/*
 * pow(f, g) function developed by using the exponentiation process
 * where pow(f, g) = sgn(f)e^(glog(|f|))
 *
 * @param real x
 *
 * @return real pow(f, g)
 */

real_t
real_pow(real_t x, real_t n)
{
        /* Domain check */
        if (real_isnull(x)) {
                return real_isnull(n) ? NAN : x;
        }

        /* Declaration of variables and structures */
        real_t s, y, z, w, k, h;

        /* Mathematical algorithm */
        s = real_sgn(x);
        y = real_abs(x);
        z = real_ln(y);
        w = real_prod(n, z);
        k = real_exp(w);
        h = real_prod(s, k);

        /* Return */
        return h;
}
