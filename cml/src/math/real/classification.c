#include <stdlib.h>
#include <math.h>

#undef CML_NO_ALIASES
#define CML_NO_ALIASES

#include <cml.h>

#ifndef PREDEF_STANDARD_C99
/* FIXME: classification functions are not ANSI C complaint, should be compatible
   with c89 and c99. */

        #ifndef isnan
                #define isnan(X) __isnan(X)
        #endif

        #ifndef isinf
                #define isinf(X) __isinf(X)
        #endif

        #ifndef isfinite
                #define isfinite(X) __finite(X)
        #endif
#endif


__CML_EXTERN_INLINE bool
__isinteger(real_t x)
{
        mint_t x_int = (mint_t) x;
        return real_isnull(x - x_int);
}


__CML_EXTERN_INLINE bool
__ismult(real_t x, real_t y)
{
        real_t z = real_div(x, y);
        mint_t z_int = (mint_t) z;
        return real_isnull(z - z_int);
}


bool
real_equal(real_t x, real_t y)
{
        return real_abs(real_sub(x, y)) < CML_FLT_EPSILON;
}


bool
real_isfinite(real_t x)
{
        return isfinite(x);
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
real_isinf(real_t x)
{
        return isinf(x);
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
real_isnan(real_t x)
{
        return isnan(x);
}


bool
real_isnull(real_t x)
{
        return real_equal(x, 0.0);
}
