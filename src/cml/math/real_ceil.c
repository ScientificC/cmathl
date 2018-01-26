#include <stdlib.h>
#include <cml.h>


/*
 * Returns the nearest integer not less than the given value
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_ceil(real_t x)
{
        mint_t w;

        w = (mint_t) x;
        return (x - w == 0.0) ?
               x :
               w + 1.0;
}
