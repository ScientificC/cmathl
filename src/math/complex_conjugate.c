#include <stdlib.h>
#include <cml.h>

/*
 * Let z = a + bi, define the conjugate of z (w) as w = a - bi
 *
 */

complex
complex_conjugate(complex z)
{
        /* Declaration of variables and structures */
        complex r;

        /* Mathematical algorithm */
        r = complex_new(z->re, real_opposite(z->im));

        /* Return */
        return r;
}
