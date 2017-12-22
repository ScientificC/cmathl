#include <stdlib.h>
#include "../../../includes/cml.h"

/*
 * It can be shown that, let z = a + bi a complex number, the multiplicative inverse of z (w), with a⋅b ≠ 0, is
 * W = conjugate(z) / abs(z)^2
 *
 */

complex
complex_inverse(complex self)
{
        // Declaration of structures
        complex z, h;
        real *x;
        real a, b, i, m, n;


        // Mathematical algorithm
        z = self->conjugate(self);
        x = z->parts(z);
        a = self->abs(self);
        i = real_new(2.0);
        b = a->pow(a, i);
        n = x[0]->div(x[0], b);
        m = x[1]->div(x[1], b);

        h = complex_new(n, m);

        // Free structures
        free(z);
        free(x);
        free(a);
        free(b);
        free(i);

        // Return
        return h;
}
