#include <stdlib.h>
#include "include/math.h"

complex
complex_div(complex self, complex z)
{
        // Declaration of structures
        complex r, w;

        // Mathematical algorithm
        r = z->inverse(z);
        w = self->prod(self, r);

        // Free structures
        free(r);

        // Return
        return w;
}
