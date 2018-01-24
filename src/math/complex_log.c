#include <stdlib.h>
#include <cml.h>

/*
 * Log(z) = ln|z| + i*arg(z)
 */

complex
complex_log(complex z)
{
        /* Declaration of variables and structures */
        complex w;
        real_t a, x, y;

        /* Mathematical algorithm */
        a = complex_abs(z);
        x = real_ln(a);
        y = complex_arg(z);
        w = complex_new(x, y);

        /* Return */
        return w;
}
