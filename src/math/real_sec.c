#include <stdlib.h>
#include <cml.h>

/*
 * sec(x) function developed by using trigonometric identities
 *
 * @param real x
 *
 * @return real sec(x)
 */

real_t
real_sec(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, h;

        /* Mathematical algorithm */
        y = real_cos(x);
        h = real_inverse(y);

        /* Return */
        return h;
}
