#include <stdlib.h>
#include <cml.h>

complex
complex_sec(complex z)
{
        /* Domain check */
        complex c = complex_cos(z);
        real_t a = complex_abs(c);
        if (!real_isnull(a)) {
                free(c);
                return complex_new(NAN, NAN);
        }

        /* Declaration of variables and structures */
        complex w;

        /* Mathematical algorithm */
        w = complex_inverse(c);

        /* Free structures */
        free(c);

        /* Return */
        return w;
}
