#include <stdlib.h>
#include <cml.h>

complex
complex_scalar_prod(complex z, real_t k)
{
        /* Declaration of variables and structures */
        complex w;
        real_t x, y;

        /* Mathematical algorithm */
        x = real_prod(k, z->p[0]);
        y = real_prod(k, z->p[1]);
        w = complex_new(x, y);

        /* Return */
        return w;
}
