#include <stdlib.h>
#include <cml.h>

/*
 * Computes real cotangent
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_cot(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, h;

        /* Mathematical algorithm */
        y = real_sin(x);
        h = real_is_null(y) ?
            NAN :
            real_div(real_cos(x), y);

        /* Return */
        return h;
}
