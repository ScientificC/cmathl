#include <stdlib.h>
#include <cml.h>

/*
 * Hyperbolic sine "real_sinh(x)" function developed by using Euler relationships
 *
 * @param real x
 *
 * @return real real_sinh(x)
 */

real_t
real_sinh(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, z, w, k, c, h;

        /* Mathematical algorithm */
        c = MFLOAT_T(2.0);
        y = real_opposite(x);
        z = real_exp(x);
        w = real_exp(y);
        k = real_sub(z, w);
        h = real_div(k, c);

        /* Return */
        return h;
}
