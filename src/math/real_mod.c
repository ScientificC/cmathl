#include <stdlib.h>
#include <cml.h>

real
real_mod(real x, real y)
{
        /* Declaration of structures */
        real z, w, k;

        /* Mathematical algorithm */
        z = real_div_e(x, y);
        w = real_prod(y, z);
        k = real_sub(x, w);

        /* Free structures */
        free(z);
        free(w);

        /* Return */
        return k;
}
