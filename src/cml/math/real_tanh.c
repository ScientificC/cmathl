#include <stdlib.h>
#include <cml.h>

/*
 * Hyperbolic tangent "tanh(x)" function developed by using Euler relationships
 *
 * @param real x
 *
 * @return real tanh(x)
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
