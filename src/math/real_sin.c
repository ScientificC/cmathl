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

real
real_sin(real x)
{
        /* Domain check */
        real c = real_new(PI);
        if (real_ismult(x, c)) {
                free(c);
                return real_new(0.0);
        }

        /* Declaration of variables and structures */
        real s, y, z, w, h;
        mfloat_t r;


        /* Mathematical algorithm */
        s = real_sgn(x);
        y = real_abs(x);
        z = real_ared(y);

        r = (mfloat_t) __sin__(real_value(z));

        w = real_new(r);
        h = real_prod(w, s);

        /* Free structures */
        free(s);
        free(y);
        free(z);
        free(w);
        free(c);

        /* Return */
        return h;
}
