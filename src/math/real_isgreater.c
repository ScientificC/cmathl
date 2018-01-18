#include <stdlib.h>
#include <cml.h>


CML_EXTERN_INLINE bool
__isgreater(mfloat_t x, mfloat_t y)
{
        return x > y;
}

bool
real_isgreater(real x, real y)
{
        return __isgreater(real_value(x), real_value(y));
}
