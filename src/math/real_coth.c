#include <stdlib.h>
#include <cml.h>

/*
 * Hyperbolic cotangent "coth(x)" function developed by using Euler relationships
 *
 * @param real x
 *
 * @return real coth(x)
 */

real
real_coth(real x)
{
        /* Domain check */

        /* Declaration of variables and structures */
        real y, z, w, h;

        /* Mathematical algorithm */
        y = real_cosh(x);
        z = real_sinh(x);
        w = real_inverse(z);
        h = real_prod(y, w);

        /* Free structures */
        free(y);
        free(z);
        free(w);

        /* Return */
        return h;
}
