#include <stdlib.h>
#include <cml.h>


_CML_EXTERN_INLINE bool
__isless(mfloat_t x, mfloat_t y)
{
        return x < y;
}

bool
real_isless(real x, real y)
{
        return __isless(real_value(x), real_value(y));
}
