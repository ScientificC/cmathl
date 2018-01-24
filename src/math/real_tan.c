#include <stdlib.h>
#include <cml.h>

/*
 * tan(x) function developed by using trigonometric identities
 *
 * @param real x
 *
 * @return real tan(x)
 */

real_t
real_tan(real_t x)
{
        /* Declaration of variables and structures */
        real_t y;

        /* Mathematical algorithm */
        y = real_cos(x);

        return real_is_null(y) ?
               NAN :
               real_div(real_sin(x), y);;
}
