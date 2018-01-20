#include <stdlib.h>
#include <cml.h>

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
        y = real_opposite(x);
        z = real_exp(x);
        w = real_exp(y);
        k = real_add(z, w);
        h = real_div(z, c);

        // Free structures
        free(y);
        free(z);
        free(w);
        free(k);
        free(c);

        // Return
        return h;
}
