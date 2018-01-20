#include <stdlib.h>
#include <cml.h>


CML_EXTERN_INLINE bool
__isnull(mfloat_t x)
{
        return x == 0.0;
}

bool
real_isnull(real x)
{
        return __isnull(real_value(x));
}
