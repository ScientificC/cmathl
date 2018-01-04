#include <stdlib.h>
#include "include/math.h"

/*
 * Hyperbolic tangent "tanh(x)" function developed by using Euler relationships
 *
 * @param real x
 *
 * @return real tanh(x)
 */

real
real_tanh(real x)
{
        // Domain check

        // Declaration of variables and structures
        real y, z, w, h;

        // Mathematic algorithm
        y = x->sinh(x);
        z = x->cosh(x);
        w = z->inverse(z);
        h = y->prod(y, w);

        // Free structures
        free(y);
        free(z);
        free(w);

        // Return
        return h;
}
