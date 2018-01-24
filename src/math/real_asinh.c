#include <stdlib.h>
#include <cml.h>

/* asinh(x) = log(x + sqrt(x² + 1)) */

real_t
real_asinh(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, z, w, k, b, c, h;

        /* Mathematical algorithm */
        b = MFLOAT_T(2.0);
        c = MFLOAT_T(1.0);
        y = real_pow(x, b);
        z = real_add(y, c);
        w = real_sqrt(z);
        k = real_add(x, w);
        h = real_ln(k);

        /* Return */
        return h;
}
