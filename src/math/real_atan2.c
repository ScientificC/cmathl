#include <stdlib.h>
#include <cml.h>

/*
 * atan2(y, x) = HALFPI*sgn(y) - atan(x/y)
 *
 */

real
real_atan2(real y, real x)
{
        // Declaration of structures
        real s, h, k, j, z, w;

        // Mathematical algorithm
        s = y->sgn(y);
        h = real_new(HALFPI);
        k = x->div(x, y);
        j = k->atan(k);
        z = h->prod(h, s);
        w = z->sub(z, j);

        // Free structures
        free(s);
        free(h);
        free(k);
        free(j);
        free(z);

        // Return
        return w;
}
