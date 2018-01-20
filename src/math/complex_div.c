#include <stdlib.h>
#include <cml.h>

complex
complex_div(complex z, complex k)
{
        // Declaration of structures
        complex r, w;

        // Mathematical algorithm
        r = complex_inverse(k);
        w = complex_prod(z, r);

        // Free structures
        free(r);

        // Return
        return w;
}
