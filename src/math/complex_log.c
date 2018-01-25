#include <stdlib.h>
#include <cml.h>

/*
 * Log(z) = ln|z| + i*arg(z)
 */

complex_t
complex_log(complex_t z)
{
        /* Declaration of variables and structures */
        complex_t w;
        real_t a, x, y;

        /* Mathematical algorithm */
        a = complex_abs(z);
        x = real_ln(a);
        y = complex_arg(z);
        w = complex(x, y);

        /* Return */
        return w;
}
