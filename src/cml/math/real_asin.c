#include <stdlib.h>
#include <cml.h>

/* asin(x) = atan(x / sqrt(1 − x²)) */

real_t
real_asin(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, z, w, k, b, c, h;

        /* Mathematical algorithm */
        b = (2.0);
        c = (1.0);
        y = real_pow(x, b);
        z = real_sub(c, y);
        w = real_sqrt(z);
        k = real_div(x, w);
        h = real_atan(k);

        /* Return */
        return h;
}
