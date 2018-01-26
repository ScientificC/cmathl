#include <stdlib.h>
#include <cml.h>

/*
 * ln(x) function developed by using hyperbolic definition of Taylor Series
 * where ln(x) = arctanh((x^2 - 1)/(x^2 + 1))
 *
 * @param real x
 *
 * @return real log(x)
 */

real_t
real_ln(real_t x)
{
        /* Domain check */
        if (x <= 0) {
                return NAN;
        }

        /* Declaration of variables and structures */
        real_t y, z, w, k, h;

        /* Mathematical algorithm */
        y = real_prod(x, x);
        z = (y - 1.0);
        w = (y + 1.0);
        k = real_div(z, w);
        h = real_atanh(k);

        /* Return */
        return h;

}
