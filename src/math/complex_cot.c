#include <stdlib.h>
#include <cml.h>

complex
complex_cot(complex z)
{
        /* Domain check */
        complex s = complex_sin(z);
        real_t a = complex_abs(s);
        if (!real_isnull(a)) {
                free(s);
                return complex_new(NAN, NAN);
        }

        /* Declaration of variables and structures */
        complex c, w;

        /* Mathematical algorithm */
        c = complex_cos(z);
        w = complex_div(c, s);

        /* Free structures */
        free(c);
        free(s);

        /* Return */
        return w;
}
