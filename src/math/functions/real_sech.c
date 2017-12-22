#include <stdlib.h>
#include "../../../includes/cml.h"

/*
 * "sech(x)" function developed by using Euler relationships
 *
 * @param real x
 *
 * @return real sech(x)
 */

real
real_sech(real x)
{
        // Domain check

        // Declaration of variables and structures
        real y, h;

        // Mathematic algorithm
        y = x->cosh(x);
        h = y->inverse(y);

        // Free structures
        free(y);

        // Return
        return h;
}
