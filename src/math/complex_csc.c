#include <stdlib.h>
#include <cml.h>

complex
complex_csc(complex self)
{
        // Domain check
        complex s = complex_sin(self);
        real a = complex_abs(s);
        if (!real_isnull(a)) {
                free(a);
                free(s);
                return complex_new(NAN, NAN);
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
