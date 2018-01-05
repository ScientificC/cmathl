#include <stdlib.h>
#include <cml.h>

/*
 * tan(x) function developed by using trigonometric identities
 *
 * @param real x
 *
 * @return real tan(x)
 */

real
real_tan(real x)
{
        // Declaration of structures
        real y, z, h;

        // Mathematical algorithm
        z = x->sin(x);
        y = x->cos(x);
        h = y->isNull(y) ? real_new(NAN) : z->div(z, y);

        // Free structures
        free(y);
        free(z);

        // Return
        return h;
}
