#include <stdlib.h>
#include <cml.h>

complex_t
complex_scalar_prod(complex_t z, real_t k)
{
        /* Declaration of variables and structures */
        complex_t w;
        real_t x, y;

        /* Mathematical algorithm */
        x = real_prod(k, z.p[0]);
        y = real_prod(k, z.p[1]);
        w = complex(x, y);

        /* Return */
        return w;
}
