#include <stdlib.h>
#include <cml.h>

/*
 * sin(Z) = (sin(a) * ((e^b + e^-b) / 2) + (Cos(a) * (e^b - e^-b) / 2))i
 * sin(Z) = (sin(a) * cosh(b)) + (cos(a) * sinh(b))i
 *
 * @param complex z
 *
 * @return complex sin(z)
 *
 */

complex
complex_sin(complex z)
{
        // Declaration of structures
        complex w;
        real *x;
        real k, h, a, b, n, m;

        // Mathematical algorithm
        x = complex_get_parts(z);

        k = real_sin(x[0]);
        h = real_cos(x[0]);
        a = real_cosh(x[1]);
        b = real_sinh(x[1]);

        n = real_prod(k, a);
        m = real_prod(h, b);

        w = complex_new(n, m);

        // Free structures
        free(x);
        free(k);
        free(h);
        free(a);
        free(b);
        free(n);
        free(m);

        // Return
        return w;
}
