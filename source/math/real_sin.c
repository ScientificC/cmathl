#include <stdlib.h>
#include "includes/cml.h"

/*
 * sin(x) function developed by using Taylor Series
 *
 * @param real x
 *
 * @return real sin(x)
 */

CML_EXTERN_INLINE double
__sin__(double x)
{
        double ai, p;
        int i;

        ai = x;
        p = ai;

        for (i = 1; i <= CML_SERIES_TOP_IT_L; ++i) {
                ai = -ai*(x)*(x)/(2*i*(2*i+1));
                p = p + ai;
        }

        return p;
}

real
real_sin(real x)
{
        // Domain check
        real c = real_new(PI);
        if (x->isMult(x, c)) {
                free(c);
                return real_new(0.0);
        }

        // Declaration of variables and structures
        real s, y, z, w, h;
        double r;


        // Mathematical algorithm
        s = x->sgn(x);
        y = x->abs(x);
        z = y->ared(y);

        r = __sin__(z->value(z));

        w = real_new(r);
        h = w->prod(w, s);

        // Free structures
        free(s);
        free(y);
        free(z);
        free(w);
        free(c);

        // Return
        return h;
}
