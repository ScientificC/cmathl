#include <stdlib.h>
#include <cml.h>

/*
 * "sech(x)" function developed by using Euler relationships
 *
 * @param real x
 *
 * @return real sech(x)
 */

real
real_sech(real x)
{
        /* Domain check */

        /* Declaration of variables and structures */
        real y, h;

        /* Mathematical algorithm */
        y = real_cosh(x);
        h = real_inverse(y);

        /* Free structures */
        free(y);

        /* Return */
        return h;
}
