#include <stdlib.h>
#include "include/math.h"

/*
 * pow(f, g) function developed by using the exponentiation process
 * where pow(f, g) = sgn(f)e^(glog(|f|))
 *
 * @param real x
 *
 * @return real pow(f, g)
 */

real
real_pow(real x, real n)
{
        // Domain check
        if (x->isNull(x)) {
                return n->isNull(n) ? real_new(NAN) : x;
        }

        // Declaration of structures
        real s, y, z, w, k, h;

        // Mathematical algorithm
        s = x->sgn(x);
        y = x->abs(x);
        z = y->ln(y);
        w = n->prod(n, z);
        k = w->exp(w);
        h = s->prod(s, k);

        // Free structures
        free(s);
        free(y);
        free(z);
        free(w);
        free(k);

        // Return
        return h;
}
