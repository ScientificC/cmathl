#include <stdlib.h>
#include "include/math.h"

real
real_mod(real x, real y)
{
        // Declaration of structures
        real z, w, k;

        // Mathematical algorithm
        z = x->divE(x, y);
        w = y->prod(y, z);
        k = x->sub(x, w);

        // Free structures
        free(z);
        free(w);

        // Return
        return k;
}
