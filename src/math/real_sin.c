#include <stdlib.h>
#include <cml.h>

_CML_EXTERN_INLINE cml_math_t
__sin__(cml_math_t x)
{
        cml_math_t ai, p;
        mint_t i;

        ai = x;
        p = ai;

        for (i = 1; i <= CML_SERIES_TOP_IT_L; ++i) {
                ai = -ai*(x)*(x)/(2*i*(2*i+1));
                p = p + ai;
        }

        return p;
}

/*
 * sin(x) function developed by using Taylor Series
 *
 * @param real x
 *
 * @return real sin(x)
 */

real_t
real_sin(real_t x)
{
        /* Domain check */
        if (real_is_mult(x, MFLOAT_T(PI))) {
                return MFLOAT_T(0.0);
        }

        /* Declaration of variables and structures */
        real_t s, y, z, w, h;

        /* Mathematical algorithm */
        s = real_sgn(x);
        y = real_abs(x);
        z = real_ared(y);
        w = MFLOAT_T((mfloat_t) __sin__(z));
        h = real_prod(w, s);

        /* Return */
        return h;
}
