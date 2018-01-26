#include <stdlib.h>
#include <cml.h>


bool
real_is_greater_or_equals(real_t x, real_t y)
{
        return real_is_greater(x, y) || real_equals(x, y);
}
