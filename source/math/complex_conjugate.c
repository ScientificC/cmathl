#include <stdlib.h>
#include "include/math.h"

/*
 * Let z = a + bi, define the conjugate of z (w) as w = a - bi
 *
 */

complex
complex_conjugate(complex self)
{
        // Declaration of structures
        complex r;
        real im;

        // Mathematical algorithm
        im = self->imaginary(self);
        r = complex_new(self->real(self), im->opposite(im));

        // Free structures
        /* free(im); don't let im be free! */

        // Return
        return r;
}
