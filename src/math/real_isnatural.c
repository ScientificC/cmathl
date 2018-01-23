#include <stdlib.h>
#include <cml.h>


_CML_EXTERN_INLINE bool
__isnatural(mfloat_t x)
{
        return (__isinteger(x) && x > 0);
}

bool
real_isnatural(real x)
{
        return __isnatural(real_value(x));
}
