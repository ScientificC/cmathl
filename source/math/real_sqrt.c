#include <stdlib.h>
#include <cml.h>

/**
 * root(f) function developed by using the exponentiation process
 *
 * @param real x
 *
 * @return real root(f)
 */

real
real_sqrt(real x)
{
        // Declaration of structures
        real w, y;

        // Mathematical algorithm
        w = real_new(2.0);
        y = x->root(x, w);

        // Free structures
        free(w);

        // Return
        return y;
}
