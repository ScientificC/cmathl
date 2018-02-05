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
        return real_isnull(x - w) ?
               x :
               w + 1.0;
}


/*
 * Return the largest integer value less than or equal to x.
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_floor(real_t x)
{
        return (real_t) ((mint_t) x);
}
