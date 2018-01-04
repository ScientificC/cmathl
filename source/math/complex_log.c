#include <stdlib.h>
#include "include/math.h"

/*
 * Log(z) = ln|z| + i*arg(z)
 */

complex
complex_log(complex self)
{
        // Declaration of structures
        complex w;
        real a, x, y;

        // Mathematic algorithm
        a = self->abs(self);
        x = a->ln(a);
        y = self->arg(self);
        w = complex_new(x, y);

        // Free structures
        free(a);

        // Return
        return w;
}
