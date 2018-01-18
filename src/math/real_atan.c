#include <stdlib.h>
#include <cml.h>

CML_EXTERN_INLINE double
__atan__(double x)
{
        mint_t i;
        double ai_n = x,
               p = ai_n;

        for (i = 1; i <= CML_SERIES_TOP_IT_L; i += 2) {
                ai_n = -ai_n*x*x;
                p += ai_n/((double) i + 2.0);
        }

        return p;
}


real
real_atan(real x)
{
        // Domain check
        real a, u;
        a = real_abs(x);
        u = real_new(1.0);

        /*
           if (real_isgreater_or_equals(a, u)) {
                free(a);
                free(u);
                return real_new(NAN);
           }
         */


        // Declaration of structures
        mfloat_t y;
        real s, h, w;

        // Mathematical algorithm
        s = real_sgn(x);
        y = (mfloat_t) __atan__(real_value(a));
        h = real_new(y);
        w = real_prod(s, h);

        // Free structures
        free(a);
        free(u);
        free(s);
        free(h);

        // Return
        return w;
}
