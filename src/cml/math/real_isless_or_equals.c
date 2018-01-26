#include <stdlib.h>
#include <cml.h>


bool
real_is_less_or_equals(real_t x, real_t y)
{
        return real_is_less(x, y) || real_equals(x, y);
}
