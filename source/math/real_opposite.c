#include <stdlib.h>
#include "include/math.h"

real
real_opposite(real x)
{
        // Declaration of structures
        real y, h;
        // Mathematical algorithm
        y = real_new(-1.0);
        h = x->prod(x, y);

        // Free structures
        free(y);

        // Return
        return h;
}
