#include <stdlib.h>
#include "include/math.h"

complex
complex_csc(complex self)
{
        // Domain check
        complex s = complex_sin(self);
        real a = complex_abs(s);
        if (!real_isnull(a)) {
                free(a);
                free(s);
                return complex_new(real_new(NAN), real_new(NAN));
        }

        free(a);

        // Declaration of structures
        complex w;

        // Mathematical algorithm
        w = complex_inverse(s);

        // Free structures
        free(s);

        // Return
        return w;
}
