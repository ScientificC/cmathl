#include <stdlib.h>
#include <cml.h>

/* An angle x is reduced to the interval [0, 2pi] by subtracting a number k of
 * 2pi radians, where k is the integer division between x and 2pi
 */

real
real_ared(real x)
{
        /* Declaration of structures */
        real two_pi, z, k, w;

        /* Mathematical algorithm */
        two_pi = real_new(TWOPI);
        z = real_div_e(x, two_pi);
        k = real_prod(z, two_pi);
        w = real_sub(x, k);

        /* Free structures */
        free(two_pi);
        free(k);
        free(z);

        /* Return */
        return w;
}
