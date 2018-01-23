#include <stdlib.h>
#include <cml.h>

/*
 * tan(x) function developed by using trigonometric identities
 *
 * @param real x
 *
 * @return real tan(x)
 */

real
real_tan(real x)
{
        /* Declaration of structures */
        real y, z, h;

        /* Mathematical algorithm */
        z = real_sin(x);
        y = real_cos(x);
        h = real_isnull(y) ?
            real_new(NAN) :
            real_div(z, y);

        /* Free structures */
        free(y);
        free(z);

        /* Return */
        return h;
}
