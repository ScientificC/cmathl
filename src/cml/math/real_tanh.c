#include <stdlib.h>
#include <cml.h>

/*
 * Computes real hyperbolic tangent
 * --| tanh(x) = sinh(x) / cosh(x)
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_tanh(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, z, w, h;

        /* Mathematical algorithm */
        y = real_sinh(x);
        z = real_cosh(x);
        w = real_inverse(z);
        h = real_prod(y, w);

        /* Return */
        return h;
}
