#include <stdlib.h>
#include "includes/cml.h"

/*
 * logb(z) = log(z)/log(b)
 */
complex
complex_log_b(complex self, complex b)
{
        // Declaration of structures
        complex k, h, w;

        // Mathematic algorithm
        k = self->log(self);
        h = b->log(b);
        w = k->div(k, h);

        // Free structures
        free(k);
        free(h);

        // Return
        return w;
}
