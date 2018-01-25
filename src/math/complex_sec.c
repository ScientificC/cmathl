#include <stdlib.h>
#include <cml.h>

complex_t
complex_sec(complex_t z)
{
        /* Domain check */
        complex_t c = complex_cos(z);
        real_t a = complex_abs(c);
        if (!real_is_null(a)) {
                return complex(NAN, NAN);
        }

        /* Declaration of variables and structures */
        complex_t w;

        /* Mathematical algorithm */
        w = complex_inverse(c);

        /* Return */
        return w;
}
