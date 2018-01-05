#include <stdlib.h>
#include <cml.h>

/*
 * exp(Z) = e^Z = (e^a * Cos(b) + e^a * Sin(b)i)
 *
 * @param complex z: Exponent of the function
 *
 * @return complex e^z
 *
 */

complex
complex_exp(complex z)
{
        // Declaration of structures
        complex w;
        real *p;
        real n, m, h, x, y;

        // Mathematical algorithm
        p = z->parts(z);
        h = real_exp(p[0]);
        n = real_cos(p[1]);
        m = real_sin(p[1]);
        x = real_prod(h, n);
        y = real_prod(h, m);

        w = complex_new(x, y);

        // Free structures
        free(p);
        free(n);
        free(m);
        free(h);
        free(x);
        free(y);

        // Return
        return w;
}
