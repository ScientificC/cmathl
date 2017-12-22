#include <stdlib.h>
#include "includes/cml.h"

double
__atan__(double x)
{
        int i;
        double ai_n = x,
               p = ai_n;

        for (i = 1; i <= TOPL; i += 2) {
                ai_n = -ai_n*x*x;
                p += ai_n/((double) i + 2.0);
        }

        return p;
}


real
real_atan(real x)
{
        // Domain check
        real a, u;
        a = x->abs(x);
        u = real_new(1.0);
        /*
           if (a->isGreaterOrEquals(a, u)) {
              free(a);
              free(u);
              return real_new(NAN);
           }
         */


        // Declaration of structures
        double y;
        real s, h, w;

        // Mathematical algorithm
        s = x->sgn(x);
        y = __atan__(a->value(a));
        h = real_new(y);
        w = s->prod(s, h);

        // Free structures
        free(a);
        free(u);
        free(s);
        free(h);

        // Return
        return w;
}
