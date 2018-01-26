#include <stdlib.h>
#include <cml.h>


/*
 * The logarithm logb(x) can be computed from the logarithms of x and b with
 * respect to an arbitrary base k using the following formula,
 * --| log_b(x) = log_k(x) / log_k(b)
 *
 * @param real_t x
 * @param real_t b
 * @return real_t
 */

real_t
real_log_b(real_t x, real_t b)
{
        /* Declaration of variables and structures */
        real_t y, z, w;

        /* Mathematical algorithm */
        y = real_log(x);
        z = real_log(b);
        w = real_div(y, z);

        /* Return */
        return w;

}
