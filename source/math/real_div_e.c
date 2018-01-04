#include <stdlib.h>
#include "include/math.h"

real
real_div_e(real x, real y)
{
        // Declaration of structures
        real z, w;

        // Mathematical algorithm
        z = x->div(x, y);
        w = z->floor(z);

        // Free structures
        free(z);

        // Return
        return w;
}
