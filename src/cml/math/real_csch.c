#include <stdlib.h>
#include <cml.h>

/*
 * "csch(x)" function developed by using Euler relationships
 *
 * @param real x
 *
 * @return real csch(x)
 */

real_t
real_csch(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, h;

        /* Mathematical algorithm */
        y = real_sinh(x);
        h = real_inverse(y);

        /* Return */
        return h;
}
