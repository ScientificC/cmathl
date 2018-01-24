#include <stdlib.h>
#include <cml.h>

/*
 * cos(x) function developed by using Taylor Series
 *
 * @param real x
 *
 * @return real cos(x)
 */

real_t
real_cos(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, z, h;

        /* Mathematical algorithm */
        y = real_abs(x);
        z = real_add(y, MFLOAT_T(HALFPI));
        h = real_sin(z);

        /* Return */
        return h;
}
