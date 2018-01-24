#include <stdlib.h>
#include <cml.h>

complex
complex_csc(complex self)
{
        /* Domain check */
        complex s = complex_sin(self);
        real_t a = complex_abs(s);
        if (!real_is_null(a)) {
                free(s);
                return complex_new(NAN, NAN);
        }

        /* Declaration of variables and structures */
        complex w;

        /* Mathematical algorithm */
        w = complex_inverse(s);

        /* Free structures */
        free(s);

        /* Return */
        return w;
}
