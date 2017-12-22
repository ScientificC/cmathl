#include <stdlib.h>
#include "includes/cml.h"

/*
 * exp(Z) = e^Z = (e^a * Cos(b) + e^a * Sin(b)i)
 *
 * @param complex z: Exponent of the function
 *
 * @return complex e^z
 *
 */

complex
complex_exp(complex self)
{
        // Declaration of structures
        complex w;
        real *p;
        real n, m, h, x, y;

        // Mathematical algorithm
        p = self->parts(self);
        h = p[0]->exp(p[0]);
        n = p[1]->cos(p[1]);
        m = p[1]->sin(p[1]);
        x = h->prod(h, n);
        y = h->prod(h, m);

        w = complex_new(x, y);

        // Free structures
        free(p);
        free(n);
        free(m);
        free(h);

        // Return
        return w;
}
