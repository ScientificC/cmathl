#include <stdlib.h>
#include <cml.h>

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
