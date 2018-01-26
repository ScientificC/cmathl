#include <stdlib.h>
#include <cml.h>

/*
 * Computes real tangent
 * --| tan(x) = sin(x) / cos(x)
 *
 * @param real_t x
 * @return real_t
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
