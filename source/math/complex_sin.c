#include <stdlib.h>
#include "include/math.h"

/*
 * sin(Z) = (sin(a) * ((e^b + e^-b) / 2) + (Cos(a) * (e^b - e^-b) / 2))i
 * sin(Z) = (sin(a) * cosh(b)) + (cos(a) * sinh(b))i
 *
 * @param complex self
 *
 * @return complex sin(self)
 *
 */

complex
complex_sin(complex self)
{
        // Declaration of structures
        complex w;
        real *x;
        real k, h, a, b, n, m;

        // Mathematical algorithm
        x = self->parts(self);

        k = x[0]->sin(x[0]);
        h = x[0]->cos(x[0]);
        a = x[1]->cosh(x[1]);
        b = x[1]->sinh(x[1]);

        n = k->prod(k, a);
        m = h->prod(h, b);

        w = complex_new(n, m);

        // Free structures
        free(x);
        free(k);
        free(h);
        free(a);
        free(b);

        // Return
        return w;
}
