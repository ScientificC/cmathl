#include <stdlib.h>
#include <cml.h>

/*
 * Computes real hyperbolic cotangent
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_coth(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, z, w, h;

        /* Mathematical algorithm */
        y = real_cosh(x);
        z = real_sinh(x);
        w = real_inverse(z);
        h = real_prod(y, w);

        /* Return */
        return h;
}
