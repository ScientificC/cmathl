#include <stdlib.h>
#include "include/math.h"

/*
 * "csch(x)" function developed by using Euler relationships
 *
 * @param real x
 *
 * @return real csch(x)
 */

real
real_csch(real x)
{
        // Domain check

        // Declaration of variables and structures
        real y, h;

        // Mathematic algorithm
        y = x->sinh(x);
        h = y->inverse(y);

        // Free structures
        free(y);

        // Return
        return h;
}
