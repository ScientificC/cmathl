#include <stdlib.h>
#include <cml.h>

complex_t
complex_tanh(complex_t z)
{
        /* Domain check */
        complex_t c = complex_cosh(z);
        real_t a = complex_abs(c);
        if (!real_is_null(a)) {
                return complex(NAN, NAN);
        }

        /* Declaration of variables and structures */
        complex_t s, w;

        /* Mathematical algorithm */
        s = complex_sinh(z);
        w = complex_div(s, c);

        /* Return */
        return w;
}
