#include <stdlib.h>
#include <cml.h>

real
real_opposite(real x)
{
        /* Declaration of structures */
        real y, h;
        /* Mathematical algorithm */
        y = real_new((mfloat_t) -1.0);
        h = real_prod(x, y);

        /* Free structures */
        free(y);

        /* Return */
        return h;
}
