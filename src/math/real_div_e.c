#include <stdlib.h>
#include <cml.h>

real
real_div_e(real x, real y)
{
        /* Declaration of structures */
        real z, w;

        /* Mathematical algorithm */
        z = real_div(x, y);
        w = real_floor(z);

        /* Free structures */
        free(z);

        /* Return */
        return w;
}
