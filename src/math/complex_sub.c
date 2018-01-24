#include <stdlib.h>
#include <cml.h>

complex
complex_sub(complex z, complex k)
{
        /* Declaration of variables and structures */
        complex h, w;
        real_t n, m;

        /* Mathematical algorithm */
        n = real_opposite(z->re);
        m = real_opposite(z->im);
        w = complex_new(n, m);
        h = complex_add(z, w);

        /* Free structures */
        free(w);

        /* Return */
        return h;
}
