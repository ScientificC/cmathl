#include <stdlib.h>
#include <cml.h>


/* Return the smallest integer value greater than or equal to x. */

real
real_ceil(real x)
{
        mint_t w;
        mfloat_t v;

        v = real_value(x);
        w = (mint_t) v;
        return (v - w == 0) ?
               real_new(v) :
               real_new(w + 1);
}
