#include <stdlib.h>
#include <cml.h>


_CML_EXTERN_INLINE bool
__ismult(real_t x, real_t y)
{
        real_t z = real_div(x, y);
        mint_t z_int = (mint_t) z;
        return ((z - z_int) == 0);
}

bool
real_ismult(real_t x, real_t y)
{
        return __ismult(x, y);
}
