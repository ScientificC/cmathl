#include <stdlib.h>
#include "includes/cml.h"

/*
 * (a + bi) · (c + di) = (ac − bd) + (ad + bc)i
 *
 */

complex
complex_prod(complex self, complex z)
{
        // Declaration of structures
        complex w;
        real n, m;
        real *x, *y;
        double a, b, c, d;

        // Mathematical algorithm
        x = self->parts(self);
        y = z->parts(z);

        a = x[0]->value(x[0]);
        b = x[1]->value(x[1]);
        c = y[0]->value(y[0]);
        d = y[1]->value(y[1]);

        n = real_new(a*c - b*d);
        m = real_new(a*d + b*c);

        w = complex_new(n, m);

        // Free structures
        free(x);
        free(y);

        // Return
        return w;
}
