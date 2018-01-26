#include <stdlib.h>
#include <cml.h>

/*
 * csc(x) function developed by using trigonometric identities
 *
 * @param real x
 *
 * @return real csc(x)
 */

real_t
real_csc(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, h;

        /* Mathematical algorithm */
        y = real_sin(x);
        h = real_inverse(y);

        /* Return */
        return h;
}
