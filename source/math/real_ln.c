#include <stdlib.h>
#include <cml.h>

/*
 * ln(x) function developed by using hyperbolic definition of Taylor Series
 * where ln(x) = arctanh((x^2 - 1)/(x^2 + 1))
 *
 * @param real x
 *
 * @return real log(x)
 */

real
real_ln(real x)
{
        // Domain check
        if (x->value(x) <= 0) {
                return real_new(NAN);
        }

        // Declaration of structures
        real y, z, w, k, h;

        // Mathematical algorithm
        y = x->prod(x, x);
        z = real_new(y->value(y) - 1);
        w = real_new(y->value(y) + 1);
        k = z->div(z, w);
        h = k->atanh(k);

        // Free structures
        free(y);
        free(z);
        free(w);
        free(k);

        // Return
        return h;

}
