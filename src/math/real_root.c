#include <stdlib.h>
#include <cml.h>

/**
 * root(f, g) function developed by using the exponentiation process
 *
 * @param real x
 *
 * @return real root(f, g)
 */

real_t
real_root(real_t x, real_t n)
{
        /* Declaration of variables and structures */
        real_t w, y, z;

        /* Mathematical algorithm */
        w = (-1.0);
        y = real_pow(n, w);
        z = real_pow(x, y);

        /* Return */
        return z;
}
