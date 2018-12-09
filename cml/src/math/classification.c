#include <stdlib.h>
#include <math.h>

#undef CML_NO_ALIASES
#define CML_NO_ALIASES

#include <cml/math.h>

#ifndef PREDEF_STANDARD_C99
/* FIXME: classification functions are not ANSI C complaint, should be compatible
 * with c89 and c99.
 */

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
__isinteger(double x)
{
        mint_t x_int = (mint_t) x;

        return cml_isnull(x - x_int);
}


__CML_EXTERN_INLINE bool
__ismult(double x, double y)
{
        double z = x/y;
        mint_t z_int = (mint_t) z;
        return cml_isnull(z - z_int);
}


int
cml_cmp(double x1, double x2, double epsilon)
{
        int exponent;
        double delta, difference;

        /* Find exponent of largest absolute value */

        {
                double max = cml_abs(x1) > cml_abs(x2) ? 
                        x1 : 
                        x2;

                cml_frexp(max, &exponent);
        }

        /* Form a neighborhood of size  2 * delta */

        delta = cml_ldexp(epsilon, exponent);

        difference = x1 - x2;

        if (difference > delta) /* x1 > x2 */
        {
                return 1;
        }
        else if (difference < -delta) /* x1 < x2 */
        {
                return -1;
        }
        else                    /* -delta <= difference <= delta */
        {
                return 0;       /* x1 ~=~ x2 */
        }
}


bool
cml_equal(double x, double y)
{
        return cml_nearequal(x, y, CML_FLT_EPSILON);
}


bool
cml_nearequal(double x, double y, double epsilon)
{
        return cml_abs(x - y) < epsilon;
}


bool
cml_isfinite(double x)
{
        return isfinite(x);
}


bool
cml_isgreaterequal(double x, double y)
{
        return cml_isgreater(x, y) || cml_equal(x, y);
}


bool
cml_isgreater(double x, double y)
{
        return x > y;
}


bool
cml_isinf(double x)
{
        return isinf(x);
}


bool
cml_isinteger(double x)
{
        return __isinteger(x);
}


bool
cml_islessequal(double x, double y)
{
        return cml_isless(x, y) || cml_equal(x, y);
}


bool
cml_isless(double x, double y)
{
        return x < y;
}


bool
cml_ismult(double x, double y)
{
        return __ismult(x, y);
}


bool
cml_isnatural(double x)
{
        return cml_isinteger(x) && x > 0.0;
}


bool
cml_isnan(double x)
{
        return isnan(x);
}


bool
cml_isnull(double x)
{
        return cml_abs(x - 0.0) < CML_FLT_EPSILON;
}
