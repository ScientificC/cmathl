#include <stdlib.h>
#include "includes/cml.h"

/*
 * Development of the Taylor series of the function e^x
 *
 * @param real x: Exponent of the function
 *
 * @return real e^x
 */

real
real_exp(real x)
{
        // Declaration of variables and structures
        int i;
        double ai, ex, value;

        // Mathematical algorithm
        value = x->value(x);
        ai = 1.0;
        ex = ai;
        for (i = 1; i < TOPL; ++i) {
                ai = ai*(value)/i;
                ex = ex + ai;
        }

        // Free structures

        // Return
        return real_new(ex);
}
