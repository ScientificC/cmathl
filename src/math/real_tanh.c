#include <stdlib.h>
#include <cml.h>

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
        y = real_sinh(x);
        z = real_cosh(x);
        w = real_inverse(z);
        h = real_prod(y, w);

        // Free structures
        free(y);
        free(z);
        free(w);

        // Return
        return h;
}
