#include <stdlib.h>
#include <cml.h>


CML_EXTERN_INLINE bool
__isinteger(mfloat_t x)
{
        mint_t x_int = (mint_t) x;
        return ((x - x_int) == 0);
}

bool
real_isinteger(real x)
{
        return __isinteger(real_value(x));
}
