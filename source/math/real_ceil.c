#include <stdlib.h>
#include "includes/cml.h"


// Returns the smallest integer value greater than or equal to x.

real
real_ceil(real x)
{
        int w;

        w = (int) x->value(x);
        return (x->value(x) - w == 0) ?
               x :
               real_new(w + 1);
}
