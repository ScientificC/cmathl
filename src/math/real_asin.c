#include <stdlib.h>
#include <cml.h>

/* asin(x) = atan(x / sqrt(1 − x²)) */

real
real_asin(real x)
{
        /* Declaration of variables and structures */
        real y, z, w, k, b, c, h;

        /* Mathematical algorithm */
        b = real_new(2.0);
        c = real_new(1.0);
        y = real_pow(x, b);
        z = real_sub(c, y);
        w = real_sqrt(z);
        k = real_div(x, w);
        h = real_atan(k);

        /* Free structures */
        free(y);
        free(z);
        free(w);
        free(k);
        free(b);
        free(c);

        /* Return */
        return h;
}
