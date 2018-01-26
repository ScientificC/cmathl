#include <stdlib.h>
#include <cml.h>

complex_t
complex_sub(complex_t z, complex_t k)
{
        /* Declaration of variables and structures */
        complex_t h, w;
        real_t n, m;

        /* Mathematical algorithm */
        n = real_opposite(z.re);
        m = real_opposite(z.im);
        w = complex(n, m);
        h = complex_add(z, w);

        /* Return */
        return h;
}
