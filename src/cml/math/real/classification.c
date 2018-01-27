#include <stdlib.h>
#include <cml.h>

_CML_EXTERN_INLINE bool
__is_integer(real_t x)
{
        mint_t x_int = (mint_t) x;
        return ((x - x_int) == 0);
}


_CML_EXTERN_INLINE bool
__is_mult(real_t x, real_t y)
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
real_is_greater_or_equals(real_t x, real_t y)
{
        return real_is_greater(x, y) || real_equals(x, y);
}


bool
real_is_greater(real_t x, real_t y)
{
        return x > y;
}


bool
real_is_integer(real_t x)
{
        return __is_integer((x));
}


bool
real_is_less_or_equals(real_t x, real_t y)
{
        return real_is_less(x, y) || real_equals(x, y);
}


bool
real_is_less(real_t x, real_t y)
{
        return x < y;
}


bool
real_is_mult(real_t x, real_t y)
{
        return __is_mult(x, y);
}


bool
real_is_natural(real_t x)
{
        return real_is_integer(x) && x > 0.0;
}


bool
real_is_null(real_t x)
{
        return x == 0.0;
}
