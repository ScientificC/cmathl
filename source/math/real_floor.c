#include <stdlib.h>
#include "includes/cml.h"

// Returns the largest integer value less than or equal to x.

real
real_floor(real x)
{
        int w;
        w = (int) x->value(x);
        return real_new(w);
}
