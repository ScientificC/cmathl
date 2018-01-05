#include <stdlib.h>
#include <cml.h>

real
complex_arg(complex z)
{
        // Declaration of structures
        real w;
        real *p;

        // Mathematical algorithm
        p = complex_get_parts(z);
        w = real_atan2(p[1], p[0]);

        // Free structures
        free(p);

        // Return
        return w;
}
