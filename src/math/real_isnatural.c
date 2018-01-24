#include <stdlib.h>
#include <cml.h>


bool
real_is_natural(real_t x)
{
        return real_is_integer(x) && x > 0.0;
}
