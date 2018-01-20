#include <stdlib.h>
#include <cml.h>

complex
complex_sec(complex z)
{
        // Domain check
        complex c = complex_cos(z);
        real a = complex_abs(c);
        if (!real_isnull(a)) {
                free(a);
                free(c);
                return complex_new(NAN, NAN);
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
