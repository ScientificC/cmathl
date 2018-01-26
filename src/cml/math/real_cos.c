#include <stdlib.h>
#include <cml.h>

/*
 * Computes real cosine
 * --| cos(x) = sin(x + HALFPI)
 * --| cos(x) = cos(-x) = cos(|x|)
 *
 * @param real_t x
 * @return real cos(x)
 */

real_t
real_cos(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, z, h;

        /* Mathematical algorithm */
        y = real_abs(x); /* cos(x) = cos(-x) = cos(|x|) */
        z = real_add(y, HALFPI);
        h = real_sin(z);

        /* Return */
        return h;
}
