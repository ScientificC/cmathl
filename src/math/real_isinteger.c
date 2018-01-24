#include <stdlib.h>
#include <cml.h>


_CML_EXTERN_INLINE bool
__is_integer(real_t x)
{
        mint_t x_int = (mint_t) x;
        return ((x - x_int) == 0);
}

bool
real_is_integer(real_t x)
{
        return __is_integer(MFLOAT_T(x));
}
