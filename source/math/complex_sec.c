#include <stdlib.h>
#include "include/math.h"

complex
complex_sec(complex z)
{
        // Domain check
        complex c = complex_cos(z);
        real a = complex_abs(c);
        if (!real_isnull(a)) {
                free(a);
                free(c);
                return complex_new(real_new(NAN), real_new(NAN));
        }

        free(a);

        // Declaration of structures
        complex w;

        // Mathematical algorithm
        w = complex_inverse(c);

        // Free structures
        free(c);

        // Return
        return w;
}
