#include <stdlib.h>
#include <cml.h>


bool
real_isgreater_or_equals(real_t x, real_t y)
{
        return real_isgreater(x, y) || real_equals(x, y);
}
