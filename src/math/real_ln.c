#include <stdlib.h>
#include <cml.h>

/*
 * ln(x) function developed by using hyperbolic definition of Taylor Series
 * where ln(x) = arctanh((x^2 - 1)/(x^2 + 1))
 *
 * @param real x
 *
 * @return real log(x)
 */

real
real_ln(real x)
{
        /* Domain check */
        if (real_value(x) <= 0) {
                return real_new(NAN);
        }

        /* Declaration of structures */
        real y, z, w, k, h;

        /* Mathematical algorithm */
        y = real_prod(x, x);
        z = real_new(real_value(y) - 1.0);
        w = real_new(real_value(y) + 1.0);
        k = real_div(z, w);
        h = real_atanh(k);

        /* Free structures */
        free(y);
        free(z);
        free(w);
        free(k);

        /* Return */
        return h;

}
