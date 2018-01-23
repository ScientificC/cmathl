#include <stdlib.h>
#include <cml.h>

/*
 * sec(x) function developed by using trigonometric identities
 *
 * @param real x
 *
 * @return real sec(x)
 */

real
real_sec(real x)
{
        /* Declaration of structures */
        real y, h;

        /* Mathematical algorithm */
        y = real_cos(x);
        h = real_inverse(y);

        /* Free structures */
        free(y);

        /* Return */
        return h;
}
