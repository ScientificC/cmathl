#include <stdlib.h>
#include <cml.h>

real
real_abs(real x)
{
        /* Declaration of structures */
        real sgn, y;

        /* Mathematical algorithm */
        sgn = real_sgn(x);
        y = real_prod(x, sgn);

        /* Free structures */
        free(sgn);

        /* Return */
        return y;
}
