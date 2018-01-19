#include <stdlib.h>
#include <cml.h>

complex
complex_scalar_prod(complex z, real k)
{
        // Declaration of structures
        complex w;
        real *p, x, y;

        // Mathematic algorithm
        p = complex_get_parts(z);
        x = real_prod(k, p[0]);
        y = real_prod(k, p[1]);
        w = complex_new_from_reals(x, y);

        // Free structures
        free(p);
        free(x);
        free(y);

        // Return
        return w;
}
