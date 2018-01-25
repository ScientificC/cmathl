#include <stdlib.h>
#include <cml.h>

/*
 * atan2(y, x) = HALFPI*sgn(y) - atan(x/y)
 *
 */

real_t
real_atan2(real_t y, real_t x)
{
        /* Declaration of variables and structures */
        real_t s, h, k, j, z, w;

        /* Mathematical algorithm */
        s = real_sgn(y);
        h = (HALFPI);
        k = real_div(x, y);
        j = real_atan(k);
        z = real_prod(h, s);
        w = real_sub(z, j);

        /* Return */
        return w;
}
