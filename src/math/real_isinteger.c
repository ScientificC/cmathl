#include <stdlib.h>
#include <cml.h>


_CML_EXTERN_INLINE bool
__isinteger(real_t x)
{
        mint_t x_int = (mint_t) x;
        return ((x - x_int) == 0);
}

bool
real_isinteger(real_t x)
{
        return __isinteger(MFLOAT_T(x));
}
