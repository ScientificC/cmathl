#include <stdlib.h>
#include "include/math.h"

complex
complex_cot(complex z)
{
        // Domain check
        complex s = complex_sin(z);
        real a = complex_abs(s);
        if (!real_isnull(a)) {
                free(a);
                free(s);
                return complex_new(real_new(NAN), real_new(NAN));
        }

        free(a);

        // Declaration of structures
        complex c, w;

        // Mathematical algorithm
        c = complex_cos(z);
        w = complex_div(c, s);

        // Free structures
        free(c);
        free(s);

        // Return
        return w;
}
