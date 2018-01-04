#include <stdlib.h>
#include "include/math.h"


CML_EXTERN_INLINE bool
__equals(double x, double y)
{
        return x == y;
}

bool
real_equals(real x, real y)
{
        return __equals(x->value(x), y->value(x));
}
