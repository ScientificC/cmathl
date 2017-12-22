#include <stdlib.h>
#include "includes/cml.h"

/*
 * cos(x) function developed by using Taylor Series
 *
 * @param real x
 *
 * @return real cos(x)
 */

real
real_cos(real x)
{
        // Declaration of structures
        real half_pi, y, z, h;

        // Mathematical algorithm
        half_pi = real_new(HALFPI);
        y = x->abs(x);
        z = y->add(y, half_pi);
        h = z->sin(z);

        // Free structures
        free(half_pi);
        free(y);
        free(z);

        // Return
        return h;
}
