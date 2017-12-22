#include <stdlib.h>
#include "includes/cml.h"

complex
complex_sub(complex self, complex z)
{
        // Declaration of structures
        complex h, w;
        real n, m, *x;

        // Mathematical algorithm
        x = z->parts(z);
        n = x[0]->opposite(x[0]);
        m = x[1]->opposite(x[1]);
        w = complex_new(n, m);

        h = self->add(self, w);

        // Free structures
        free(x);
        free(n);
        free(m);
        free(w);

        // Return
        return h;
}
