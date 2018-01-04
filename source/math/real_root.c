#include <stdlib.h>
#include "include/math.h"

/**
 * root(f, g) function developed by using the exponentiation process
 *
 * @param real x
 *
 * @return real root(f, g)
 */

real
real_root(real x, real n)
{
        // Declaration of structures
        real w, y, z;

        // Mathematical algorithm
        w = real_new(-1.0);
        y = n->pow(n, w);
        z = x->pow(x, y);

        // Free structures
        free(w);
        free(y);

        // Return
        return z;
}
