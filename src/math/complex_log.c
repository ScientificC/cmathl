#include <stdlib.h>
#include <cml.h>

/*
 * Log(z) = ln|z| + i*arg(z)
 */

complex
complex_log(complex z)
{
        /* Declaration of structures */
        complex w;
        real a, x, y;

        /* Mathematical algorithm */
        a = complex_abs(z);
        x = real_ln(a);
        y = complex_arg(z);
        w = complex_new_from_reals(x, y);

        /* Free structures */
        free(a);
        free(x);
        free(y);

        /* Return */
        return w;
}
