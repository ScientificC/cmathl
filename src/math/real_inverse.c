#include <stdlib.h>
#include <cml.h>

real
real_inverse(real x)
{
        /* Declaration of structures */
        real y, h;

        /* Mathematical algorithm */
        y = real_new((mfloat_t) 1.0);
        h = real_isnull(x) ?
            real_new(NAN) :
            real_div(y, x);

        /* Free structures */
        free(y);

        /* Return */
        return h;
}
