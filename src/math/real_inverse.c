#include <stdlib.h>
#include <cml.h>

real_t
real_inverse(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, h;

        /* Mathematical algorithm */
        y = MFLOAT_T(1.0);
        h = real_isnull(x) ?
            NAN :
            real_div(y, x);

        /* Return */
        return h;
}
