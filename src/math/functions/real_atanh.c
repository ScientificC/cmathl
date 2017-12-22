#include <stdlib.h>
#include "../../../includes/cml.h"

/*
 * atanh(x) function developed by using trigonometric identities
 *
 * @param real x
 *
 * @return real atanh(x)
 */

double
__atanh__(double x)
{
        double ai_n, p;
        int i;

        ai_n = x;
        p = ai_n;
        for (i = 1; i <= TOPL; i += 2) {
                ai_n = ai_n*x*x;
                p = p + ai_n/(i+2);
        }

        return p;
}

real
real_atanh(real x)
{
        // Declaration of structures
        real y, c, h;
        double r;

        // Mathematical algorithm
        y = x->abs(x);
        c = real_new(1.0);
        r = __atanh__(x->value(x));
        h = c->isGreater(c, y) ? real_new(r) : real_new(NAN);

        // Free structures
        free(c);
        free(y);

        // Return
        return h;
}
