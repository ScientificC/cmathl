#include <stdlib.h>
#include <cml.h>

/*
 * logb(z) = log(z)/log(b)
 */
complex_t
complex_log_b(complex_t z, complex_t b)
{
        /* Declaration of variables and structures */
        complex_t k, h, w;

        /* Mathematical algorithm */
        k = complex_log(z);
        h = complex_log(b);
        w = complex_div(k, h);

        /* Return */
        return w;
}
