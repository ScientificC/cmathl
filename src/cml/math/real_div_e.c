#include <stdlib.h>
#include <cml.h>

/*
 * Computes the quotient and remainder of integer division
 *
 * @param real_t x
 * @param real_t y
 * @return real_t
 */

real_t
real_div_e(real_t x, real_t y)
{
        /* Declaration of variables and structures */
        real_t z, w;

        /* Mathematical algorithm */
        z = real_div(x, y);
        w = real_floor(z);

        /* Return */
        return w;
}
