#include <stdlib.h>
#include <cml.h>

/*
 * atanh(x) function developed by using trigonometric identities
 *
 * @param real x
 *
 * @return real atanh(x)
 */

CML_EXTERN_INLINE cml_math_t
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

real
real_atanh(real x)
{
        // Declaration of structures
        real y, c, h;
        mfloat_t r;

        // Mathematical algorithm
        y = real_abs(x);
        c = real_new(1.0);
        r = (mfloat_t) __atanh__(real_value(x));
        h = real_isgreater(c, y) ?
            real_new(r) :
            real_new(NAN);

        // Free structures
        free(c);
        free(y);

        // Return
        return h;
}
