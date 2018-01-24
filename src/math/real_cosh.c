#include <stdlib.h>
#include <cml.h>

/*
 * Hyperbolic cosine "real_cosh(x)" function developed by using Euler relationships
 *
 * @param real x
 *
 * @return real real_cosh(x)
 */

real_t
real_cosh(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, z, w, k, c, h;

        /* Mathematical algorithm */
        c = MFLOAT_T(2.0);
        y = real_opposite(x);
        z = real_exp(x);
        w = real_exp(y);
        k = real_add(z, w);
        h = real_div(k, c);

        /* Return */
        return h;
}
