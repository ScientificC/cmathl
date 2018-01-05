#include <stdlib.h>
#include <cml.h>

/*
 * Let z = a + bi, define the conjugate of z (w) as w = a - bi
 *
 */

complex
complex_conjugate(complex z)
{
        // Declaration of structures
        complex r;
        real im;

        // Mathematical algorithm
        im = complex_get_imaginary(z);
        r = complex_new(complex_get_real(z), real_opposite(im));

        // Free structures
        /* free(im); don't let im be free! */

        // Return
        return r;
}
