#include <stdlib.h>
#include <cml.h>


bool
real_isnatural(real_t x)
{
        return real_isinteger(x) && x > 0.0;
}
