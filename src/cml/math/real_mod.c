#include <stdlib.h>
#include <cml.h>

/*
 * remainder of the floating point division operation
 *
 * @param real_t x
 * @param real_t y
 * @return real_t
 */

real_t
real_mod(real_t x, real_t y)
{
        /* Declaration of variables and structures */
        real_t z, w, k;

        /* Mathematical algorithm */
        z = real_div_e(x, y);
        w = real_prod(y, z);
        k = real_sub(x, w);

        /* Return */
        return k;
}
