#include <stdlib.h>
#include "include/math.h"

real
real_sgn(real x)
{
        int sgn;
        sgn = x->value(x) >= 0 ? 1 : -1;
        return real_new(sgn);
}
