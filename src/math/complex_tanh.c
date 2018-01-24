#include <stdlib.h>
#include <cml.h>

complex
complex_tanh(complex z)
{
        /* Domain check */
        complex c = complex_cosh(z);
        real_t a = complex_abs(c);
        if (!real_isnull(a)) {
                free(c);
                return complex_new(NAN, NAN);
        }

        /* Declaration of variables and structures */
        complex s, w;

        /* Mathematical algorithm */
        s = complex_sinh(z);
        w = complex_div(s, c);

        /* Free structures */
        free(s);
        free(c);

        /* Return */
        return w;
}
