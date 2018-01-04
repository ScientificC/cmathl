#include <stdlib.h>
#include "include/math.h"


CML_EXTERN_INLINE bool
__isgreater(double x, double y)
{
        return x > y;
}

bool
real_isgreater(real x, real y)
{
        return __isgreater(x->value(x), y->value(y));
}
