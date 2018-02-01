#include <stdlib.h>
#include <cml.h>

_CML_EXTERN_INLINE bool
__isinteger(real_t x)
{
        mint_t x_int = (mint_t) x;
        return ((x - x_int) == 0);
}


_CML_EXTERN_INLINE bool
__ismult(real_t x, real_t y)
{
        real_t z = real_div(x, y);
        mint_t z_int = (mint_t) z;
        return ((z - z_int) == 0);
}


bool
real_equals(real_t x, real_t y)
{
        return x == y;
}


bool
real_isgreaterorequals(real_t x, real_t y)
{
        return real_isgreater(x, y) || real_equals(x, y);
}


bool
real_isgreater(real_t x, real_t y)
{
        return x > y;
}


bool
real_isinteger(real_t x)
{
        return __isinteger((x));
}


bool
real_islessorequals(real_t x, real_t y)
{
        return real_isless(x, y) || real_equals(x, y);
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
        return x == 0.0;
}
