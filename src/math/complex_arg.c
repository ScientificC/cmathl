#include <stdlib.h>
#include <cml.h>

real_t
complex_arg(complex z)
{
        /* Declaration of variables and structures */
        real_t w;

        /* Mathematical algorithm */
        w = real_atan2(z->p[1], z->p[0]);

        /* Return */
        return w;
}
