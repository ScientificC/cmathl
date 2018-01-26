#include <stdlib.h>
#include <cml.h>

/* An angle x is reduced to the interval [0, 2pi] by subtracting a number k of
 * 2pi radians, where k is the integer division between x and 2pi
 */

real_t
real_ared(real_t x)
{
        /* Declaration of variables and structures */
        real_t z, k, w;

        /* Mathematical algorithm */
        z = real_div_e(x, (TWOPI));
        k = real_prod(z, (TWOPI));
        w = real_sub(x, k);

        /* Return */
        return w;
}
