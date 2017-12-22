#include <stdlib.h>
#include "includes/cml.h"


bool
__isgreater(double x, double y)
{
        return x > y;
}

bool
real_isgreater(real x, real y)
{
        return __isgreater(x->value(x), y->value(y));
}
