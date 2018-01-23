#include <stdlib.h>
#include <cml.h>


_CML_EXTERN_INLINE bool
__equals(mfloat_t x, mfloat_t y)
{
        return x == y;
}

bool
real_equals(real x, real y)
{
        return __equals(real_value(x), real_value(x));
}
