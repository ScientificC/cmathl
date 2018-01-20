#include <stdlib.h>
#include <cml.h>

// Returns the largest integer value less than or equal to x.

real
real_floor(real x)
{
        return real_new((mint_t) real_value(x));
}
