#include <stdlib.h>
#include <cml.h>

/*
 * csc(x) function developed by using trigonometric identities
 *
 * @param real x
 *
 * @return real csc(x)
 */

real
real_csc(real x)
{
        /* Declaration of structures */
        real y, h;

        /* Mathematical algorithm */
        y = real_sin(x);
        h = real_inverse(y);

        /* Free structures */
        free(y);

        /* Return */
        return h;
}
