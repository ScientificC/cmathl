#include <stdlib.h>
#include <cml.h>

complex_t
complex_tan(complex_t z)
{
        /* Domain check */
        complex_t c = complex_cos(z);
        real_t a = complex_abs(c);
        if (!real_is_null(a)) {
                return complex(NAN, NAN);
        }

        /* Declaration of variables and structures */
        complex_t s, w;

        /* Mathematical algorithm */
        s = complex_sin(z);
        w = complex_div(s, c);

        /* Return */
        return w;
}
