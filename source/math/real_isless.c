#include <stdlib.h>
#include "include/math.h"


CML_EXTERN_INLINE bool
__isless(double x, double y)
{
        return x < y;
}

bool
real_isless(real x, real y)
{
        return __isless(x->value(x), y->value(y));
}
