#include <stdlib.h>
#include "../../../includes/cml.h"


bool
real_isless_or_equals(real x, real y)
{
        return x->isLess(x, y) || x->equals(x, y);
}
