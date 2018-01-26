#include <stdlib.h>
#include <cml.h>

/*
 * Hyperbolic cotangent "coth(x)" function developed by using Euler relationships
 *
 * @param real x
 *
 * @return real coth(x)
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
