#include <stdlib.h>
#include "include/math.h"

/*
 * (a + bi) + (c + di) = (a+c) + (b+d)i
 *
 */

complex
complex_add(complex z, complex k)
{
        // Declaration of structures
        complex w;
        real n, m, *x, *y;

        // Mathematical algorithm
        x = complex_get_parts(z);
        y = complex_get_parts(k);
        n = real_add(x[0], y[0]);
        m = real_add(x[1], y[1]);
        w = complex_new(n, m);

        // Free structures
        free(x);
        free(y);
        free(n);
        free(m);

        // Return
        return w;
}
