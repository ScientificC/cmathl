#include <stdlib.h>
#include <cml.h>

real
real_inverse(real x)
{
        // Declaration of structures
        real y, h;

        // Mathematical algorithm
        y = real_new(1.0);
        h = x->isNull(x) ? real_new(NAN) : y->div(y, x);

        // Free structures
        free(y);

        // Return
        return h;
}
