#include <stdlib.h>
#include "includes/cml.h"

real
complex_arg(complex self)
{
        // Declaration of structures
        real w;
        real *p;

        // Mathematical algorithm
        p = self->parts(self);
        w = p[1]->atan2(p[1], p[0]);

        // Free structures
        free(p);

        // Return
        return w;
}
