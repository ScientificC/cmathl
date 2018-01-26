#include <stdlib.h>
#include <cml.h>

complex_t
complex_csc(complex_t z)
{
        /* Domain check */
        complex_t s = complex_sin(z);
        real_t a = complex_abs(s);
        if (!real_is_null(a)) {
                return complex(NAN, NAN);
        }

        /* Declaration of variables and structures */
        complex_t w;

        /* Mathematical algorithm */
        w = complex_inverse(s);

        /* Return */
        return w;
}
