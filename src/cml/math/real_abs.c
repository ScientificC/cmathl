#include <stdlib.h>
#include <cml.h>

/*
 * Computes absolute value of a floating point value
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_abs(real_t x)
{
        /* Declaration of variables and structures */
        real_t sgn, y;

        /* Mathematical algorithm */
        sgn = real_sgn(x);
        y = real_prod(x, sgn);

        /* Return */
        return y;
}
