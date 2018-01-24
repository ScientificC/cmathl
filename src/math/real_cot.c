#include <stdlib.h>
#include <cml.h>

/*
 * cot(x) function developed by using trigonometric identities
 *
 * @param real x
 *
 * @return real cot(x)
 */

real_t
real_cot(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, h;

        /* Mathematical algorithm */
        y = real_sin(x);
        h = real_isnull(y) ?
            NAN :
            real_div(real_cos(x), y);

        /* Return */
        return h;
}
