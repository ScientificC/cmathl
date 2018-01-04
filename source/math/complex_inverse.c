#include <stdlib.h>
#include "include/math.h"

/*
 * It can be shown that, let z = a + bi a complex number, the multiplicative inverse of z (w), with a⋅b ≠ 0, is
 * W = conjugate(z) / abs(z)^2
 *
 */

complex
complex_inverse(complex z)
{
        // Declaration of structures
        complex w, h;
        real *x;
        real a, b, i, m, n;


        // Mathematical algorithm
        w = complex_conjugate(z);
        x = complex_get_parts(w);
        a = complex_abs(z);
        i = real_new(2.0);
        b = real_pow(a, i);
        n = real_div(x[0], b);
        m = real_div(x[1], b);

        h = complex_new(n, m);

        // Free structures
        free(w);
        free(x);
        free(a);
        free(b);
        free(i);
        free(n);
        free(m);

        // Return
        return h;
}
