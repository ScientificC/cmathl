#include <stdlib.h>
#include "../../../includes/cml.h"

complex
complex_scalar_prod(complex self, real k)
{
        // Declaration of structures
        complex w;
        real *p, x, y;

        // Mathematic algorithm
        p = self->parts(self);
        x = k->prod(k, p[0]);
        y = k->prod(k, p[1]);
        w = complex_new(x, y);

        // Free structures
        free(p);

        // Return
        return w;
}
