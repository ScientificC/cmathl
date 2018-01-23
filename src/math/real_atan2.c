#include <stdlib.h>
#include <cml.h>

/*
 * atan2(y, x) = HALFPI*sgn(y) - atan(x/y)
 *
 */

real
real_atan2(real y, real x)
{
        /* Declaration of structures */
        real s, h, k, j, z, w;

        /* Mathematical algorithm */
        s = real_sgn(y);
        h = real_new(HALFPI);
        k = real_div(x, y);
        j = real_atan(k);
        z = real_prod(h, s);
        w = real_sub(z, j);

        /* Free structures */
        free(s);
        free(h);
        free(k);
        free(j);
        free(z);

        /* Return */
        return w;
}
