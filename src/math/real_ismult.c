#include <stdlib.h>
#include <cml.h>


CML_EXTERN_INLINE bool
__ismult(mfloat_t x, mfloat_t y)
{
        mfloat_t z = x/y;
        mint_t z_int = (mint_t) z;
        return ((z - z_int) == 0);
}

bool
real_ismult(real x, real y)
{
        return __ismult(real_value(x), real_value(y));
}
