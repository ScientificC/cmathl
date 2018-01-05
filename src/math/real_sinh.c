#include <stdlib.h>
#include <cml.h>

/*
 * Hyperbolic sine "real_sinh(x)" function developed by using Euler relationships
 *
 * @param real x
 *
 * @return real real_sinh(x)
 */

real
real_sinh(real x)
{
        // Domain check

        // Declaration of variables and structures
        real y, z, w, k, c, h;

        // Mathematic algorithm
        c = real_new(2.0);
        y = x->opposite(x);
        z = x->exp(x);
        w = y->exp(y);
        k = z->sub(z, w);
        h = k->div(k, c);

        // Free structures
        free(y);
        free(z);
        free(w);
        free(k);
        free(c);

        // Return
        return h;
}
