#include <stdlib.h>
#include <cml.h>

/*
 * cos(Z) = (cos(a) * ((e^b - e^-b) / 2) + (sin(a) * (e^b + e^-b) / 2))i
 * cos(Z) = (cos(a) * sinh(b)) + (sin(a) * cosh(b))i
 *
 * @param complex z
 *
 * @return complex cos(z)
 *
 */

complex
complex_cos(complex z)
{
        /* Declaration of structures */
        complex w;
        real *x;
        real k, h, a, b, n, m;

        /* Mathematical algorithm */
        x = complex_get_parts(z);

        k = real_cos(x[0]);
        h = real_sin(x[0]);
        a = real_sinh(x[1]);
        b = real_cosh(x[1]);

        n = real_prod(k, a);
        m = real_prod(h, b);

        w = complex_new_from_reals(n, m);

        /* Free structures */
        free(x);
        free(k);
        free(h);
        free(a);
        free(b);
        free(n);
        free(m);

        /* Return */
        return w;
}
