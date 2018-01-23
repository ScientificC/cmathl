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

real
real_pow(real x, real n)
{
        /* Domain check */
        if (real_isnull(x)) {
                return real_isnull(n) ?
                       real_new(NAN) :
                       real_clone(x);
        }

        /* Declaration of structures */
        real s, y, z, w, k, h;

        /* Mathematical algorithm */
        s = real_sgn(x);
        y = real_abs(x);
        z = real_ln(y);
        w = real_prod(n, z);
        k = real_exp(w);
        h = real_prod(s, k);

        /* Free structures */
        free(s);
        free(y);
        free(z);
        free(w);
        free(k);

        /* Return */
        return h;
}
