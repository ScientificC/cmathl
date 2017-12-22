#include <stdlib.h>
#include "../../../includes/cml.h"

/*
 * csc(x) function developed by using trigonometric identities
 *
 * @param real x
 *
 * @return real csc(x)
 */

real
real_csc(real x)
{
        // Declaration of structures
        real y, h;

        // Mathematical algorithm
        y = x->sin(x);
        h = y->inverse(y);

        // Free structures
        free(y);

        // Return
        return h;
}
