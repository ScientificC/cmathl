#include <stdlib.h>
#include "../../../includes/cml.h"

/*
 * cot(x) function developed by using trigonometric identities
 *
 * @param real x
 *
 * @return real cot(x)
 */

real
real_cot(real x)
{
        // Declaration of structures
        real y, z, h;

        // Mathematical algorithm
        z = x->cos(x);
        y = x->sin(x);
        h = y->isNull(y) ? real_new(NAN) : z->div(z, y);

        // Free structures
        free(z);
        free(y);

        // Return
        return h;
}
