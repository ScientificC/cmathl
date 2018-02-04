#include <stdlib.h>
#include <cml.h>

__CML_EXTERN_INLINE bool
__isinteger(real_t x)
{
        mint_t x_int = (mint_t) x;
        return (x - x_int) == 0;
}


__CML_EXTERN_INLINE bool
__ismult(real_t x, real_t y)
{
        real_t z = real_div(x, y);
        mint_t z_int = (mint_t) z;
        return (z - z_int) == 0;
}


bool
real_equal(real_t x, real_t y)
{
        return real_abs(real_sub(x, y)) < CML_FLT_EPSILON;
}


bool
real_isgreaterequal(real_t x, real_t y)
{
        return real_isgreater(x, y) || real_equal(x, y);
}


bool
real_isgreater(real_t x, real_t y)
{
        return x > y;
}


bool
real_isinteger(real_t x)
{
        return __isinteger(x);
}


bool
real_islessequal(real_t x, real_t y)
{
        return real_isless(x, y) || real_equal(x, y);
}


bool
real_isless(real_t x, real_t y)
{
        return x < y;
}


bool
real_ismult(real_t x, real_t y)
{
        return __ismult(x, y);
}


bool
real_isnatural(real_t x)
{
        return real_isinteger(x) && x > 0.0;
}


bool
real_isnull(real_t x)
{
        return real_equal(x, 0.0);
}
