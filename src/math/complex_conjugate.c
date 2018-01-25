#include <stdlib.h>
#include <cml.h>

/*
 * Let z = a + bi, define the conjugate of z (w) as w = a - bi
 *
 */

complex_t
complex_conjugate(complex_t z)
{
        /* Declaration of variables and structures */
        complex_t r;

        /* Mathematical algorithm */
        r = complex(z.re, real_opposite(z.im));

        /* Return */
        return r;
}
