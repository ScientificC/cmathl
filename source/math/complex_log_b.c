#include <stdlib.h>
#include "include/math.h"

/*
 * logb(z) = log(z)/log(b)
 */
complex
complex_log_b(complex z, complex b)
{
        // Declaration of structures
        complex k, h, w;

        // Mathematic algorithm
        k = complex_log(z);
        h = complex_log(b);
        w = complex_div(k, h);

        // Free structures
        free(k);
        free(h);

        // Return
        return w;
}
