#include <stdlib.h>
#include <cml.h>

/*
 * (a + bi) · (c + di) = (ac − bd) + (ad + bc)i
 *
 */

complex
complex_prod(complex z, complex k)
{
        // Declaration of structures
        complex w;
        real *x, *y;
        cml_math_t a, b, c, d;

        // Mathematical algorithm
        x = complex_get_parts(z);
        y = complex_get_parts(k);

        a = real_value(x[0]);
        b = real_value(x[1]);
        c = real_value(y[0]);
        d = real_value(y[1]);

        w = complex_new(a*c - b*d, a*d + b*c);

        // Free structures
        free(x);
        free(y);

        // Return
        return w;
}
