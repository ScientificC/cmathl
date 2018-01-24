#include <stdlib.h>
#include <cml.h>

/*
 * atanh(x) function developed by using trigonometric identities
 *
 * @param real x
 *
 * @return real atanh(x)
 */

_CML_EXTERN_INLINE cml_math_t
__atanh__(cml_math_t x)
{
        cml_math_t ai_n, p;
        mint_t i;

        ai_n = x;
        p = ai_n;

        for (i = 1; i <= CML_SERIES_TOP_IT_L; i += 2) {
                ai_n = ai_n*x*x;
                p = p + ai_n/(i+2);
        }

        return p;
}

real_t
real_atanh(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, c, h;

        /* Mathematical algorithm */
        y = real_abs(x);
        c = MFLOAT_T(1.0);
        h = real_is_greater(c, y) ?
            MFLOAT_T((real_t) __atanh__(x)) :
            MFLOAT_T(NAN);

        /* Return */
        return h;
}
