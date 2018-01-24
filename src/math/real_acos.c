#include <stdlib.h>
#include <cml.h>

real_t
real_acos(real_t x)
{
        /* Declaration of variables and structures */
        real_t h, y;

        /* Mathematical algorithm */
        y = real_asin(x);
        h = real_sub(MFLOAT_T(HALFPI), y);

        /* Return */
        return h;
}
