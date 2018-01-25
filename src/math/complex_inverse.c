#include <stdlib.h>
#include <cml.h>

/*
 * It can be shown that, let z = a + bi a complex number, the multiplicative inverse of z (w), with a⋅b ≠ 0, is
 * W = conjugate(z) / abs(z)^2
 *
 */

complex
complex_inverse(complex z)
{
        /* Declaration of variables and structures */
        complex w, h;
        real_t a, b, i, m, n;


        /* Mathematical algorithm */
        w = complex_conjugate(z);
        a = complex_abs(z);
        i = (2.0);
        b = real_pow(a, i);
        n = real_div(w->p[0], b);
        m = real_div(w->p[1], b);

        h = complex_new(n, m);

        /* Free structures */
        free(w);

        /* Return */
        return h;
}
