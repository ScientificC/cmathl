#include <stdlib.h>
#include "include/math.h"

/*
 * (a + bi) + (c + di) = (a+c) + (b+d)i
 *
 */

complex
complex_add(complex self, complex z)
{
        // Declaration of structures
        complex w;
        real n, m, *x, *y;

        // Mathematical algorithm
        x = self->parts(self);
        y = z->parts(z);
        n = x[0]->add(x[0], y[0]);
        m = x[1]->add(x[1], y[1]);
        w = complex_new(n, m);

        // Free structures
        free(x);
        free(y);

        // Return
        return w;
}
