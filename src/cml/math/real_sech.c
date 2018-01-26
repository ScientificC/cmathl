#include <stdlib.h>
#include <cml.h>

/*
 * "sech(x)" function developed by using Euler relationships
 *
 * @param real x
 *
 * @return real sech(x)
 */

real_t
real_sech(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, h;

        /* Mathematical algorithm */
        y = real_cosh(x);
        h = real_inverse(y);

        /* Return */
        return h;
}
