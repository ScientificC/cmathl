#include <stdlib.h>
#include <cml.h>

/*
 * Computes real hyperbolic secant function by using Euler relationships
 *
 * @param real_t x
 * @return real_t
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
