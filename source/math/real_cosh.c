#include <stdlib.h>
#include "includes/cml.h"

/*
 * Hyperbolic cosine "real_cosh(x)" function developed by using Euler relationships
 *
 * @param real x
 *
 * @return real real_cosh(x)
 */

real
real_cosh(real x)
{
        // Domain check

        // Declaration of variables and structures
        real y, z, w, k, c, h;

        // Mathematic algorithm
        c = real_new(2.0);
        y = x->opposite(x);
        z = x->exp(x);
        w = y->exp(y);
        k = z->add(z, w);
        h = z->div(z, c);

        // Free structures
        free(y);
        free(z);
        free(w);
        free(k);
        free(c);

        // Return
        return h;
}
