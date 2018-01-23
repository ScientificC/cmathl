#include <stdlib.h>
#include <cml.h>

/*
 * sinh(Z) = (cos(b) * ((e^a - e^-a) / 2) + (sin(b) * (e^a + e^-a) / 2))i
 * sinh(Z) = (cos(b) * cosh(a)) + (sin(b) * sinh(a))i
 *
 * @param complex z
 *
 * @return complex sinh(z)
 *
 */

complex
complex_sinh(complex z)
{
        /* Declaration of structures */
        complex w;
        real *x;
        real k, h, a, b, n, m;

        /* Mathematical algorithm */
        x = complex_get_parts(z);

        k = real_cos(x[1]);
        h = real_sin(x[1]);
        a = real_sinh(x[0]);
        b = real_cosh(x[0]);

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
