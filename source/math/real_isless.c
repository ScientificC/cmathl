#include <stdlib.h>
#include "includes/cml.h"


bool
__isless(double x, double y)
{
        return x < y;
}

bool
real_isless(real x, real y)
{
        return __isless(x->value(x), y->value(y));
}
