#include <stdlib.h>
#include <cml.h>

/**
 * Computes real root function by using the exponentiation process
 *
 * @param real_t x
 * @param real_t n: exponent
 * @return real_t
 */

real_t
real_root(real_t x, real_t n)
{
        /* Declaration of variables and structures */
        real_t y, z;

        /* Mathematical algorithm */
        y = real_div(1.0, n);
        z = real_pow(x, y);

        /* Return */
        return z;
}
