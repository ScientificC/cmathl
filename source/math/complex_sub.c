#include <stdlib.h>
#include "include/math.h"

complex
complex_sub(complex z, complex k)
{
        // Declaration of structures
        complex h, w;
        real n, m, *x;

        // Mathematical algorithm
        x = complex_get_parts(k);
        n = real_opposite(x[0]);
        m = real_opposite(x[1]);
        w = complex_new(n, m);

        h = complex_add(z, w);

        // Free structures
        free(x);
        free(n);
        free(m);
        free(w);

        // Return
        return h;
}
