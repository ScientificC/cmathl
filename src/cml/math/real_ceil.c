#include <stdlib.h>
#include <cml.h>


/* Return the smallest integer value greater than or equal to x. */

real_t
real_ceil(real_t x)
{
        mint_t w;

        w = (mint_t) x;
        return (x - w == 0.0) ?
               (x) :
               (w + 1.0);
}
