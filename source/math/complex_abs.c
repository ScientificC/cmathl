#include <stdlib.h>
#include "include/math.h"

real
complex_abs(complex self)
{
        // Declaration of structures
        real *x;
        real n, a, b, w, h;


        // Mathematical algorithm
        x = self->parts(self);
        n = real_new(2.0);
        a = x[0]->pow(x[0], n);
        b = x[1]->pow(x[1], n);
        w = a->add(a, b);
        h = w->sqrt(w);

        // Free structures
        free(x);
        free(n);
        free(a);
        free(b);
        free(w);

        // Return
        return h;
}
