#include <stdlib.h>
#include <cml.h>

real_t
complex_abs(complex z)
{
        /* Declaration of variables and structures */
        real_t n, a, b, w, h;

        /* Mathematical algorithm */
        n = MFLOAT_T(2.0);
        a = real_pow(creal(z), n);
        b = real_pow(cimag(z), n);
        w = real_add(a, b);
        h = real_sqrt(w);

        /* Return */
        return h;
}
