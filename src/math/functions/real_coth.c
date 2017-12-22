#include <stdlib.h>
#include "../../../includes/cml.h"

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
        // Domain check

        // Declaration of variables and structures
        real y, z, w, h;

        // Mathematic algorithm
        y = x->cosh(x);
        z = x->sinh(x);
        w = z->inverse(z);
        h = y->prod(y, w);

        // Free structures
        free(y);
        free(z);
        free(w);

        // Return
        return h;
}
