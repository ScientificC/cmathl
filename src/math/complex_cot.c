#include <stdlib.h>
#include <cml.h>

complex_t
complex_cot(complex_t z)
{
        /* Domain check */
        complex_t s = complex_sin(z);
        real_t a = complex_abs(s);
        if (!real_is_null(a)) {
                return complex(NAN, NAN);
        }

        /* Declaration of variables and structures */
        complex_t c, w;

        /* Mathematical algorithm */
        c = complex_cos(z);
        w = complex_div(c, s);

        /* Return */
        return w;
}
