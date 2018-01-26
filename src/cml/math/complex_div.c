#include <stdlib.h>
#include <cml.h>

complex_t
complex_div(complex_t z, complex_t k)
{
        /* Declaration of variables and structures */
        complex_t r, w;

        /* Mathematical algorithm */
        r = complex_inverse(k);
        w = complex_prod(z, r);

        /* Return */
        return w;
}
