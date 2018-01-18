#include <stdlib.h>
#include <cml.h>


bool
real_isless_or_equals(real x, real y)
{
        return real_isless(x, y) || real_equals(x, y);
}
