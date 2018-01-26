#include <stdlib.h>
#include <cml.h>

/*
 * Computes real secant function by using trigonometric identities
 *
 * @param real_t x
 * @return real_t
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
