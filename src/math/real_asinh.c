#include <stdlib.h>
#include <cml.h>

/* asinh(x) = log(x + sqrt(x² + 1)) */

real
real_asinh(real x)
{
        /* Declaration of variables and structures */
        real y, z, w, k, b, c, h;

        /* Mathematical algorithm */
        b = real_new(2.0);
        c = real_new(1.0);
        y = real_pow(x, b);
        z = real_add(y, c);
        w = real_sqrt(z);
        k = real_add(x, w);
        h = real_ln(k);

        /* Free structures */
        free(y);
        free(z);
        free(w);
        free(k);
        free(b);
        free(c);

        /* Return */
        return h;
}
