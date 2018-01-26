#include <stdlib.h>
#include <cml.h>

/*
 * Computes real arc tangent, using signs to determinate cuadrants
 * --| atan2(y, x) = HALFPI*sgn(y) - atan(x/y)
 *
 * @param real_t y
 * @param real_t x
 * @return real_t
 */

real_t
real_atan2(real_t y, real_t x)
{
        /* Declaration of variables and structures */
        real_t s, k, j, z, w;

        /* Mathematical algorithm */
        s = real_sgn(y);
        k = real_div(x, y);
        j = real_atan(k);
        z = real_prod(HALFPI, s);
        w = real_sub(z, j);

        /* Return */
        return w;
}
