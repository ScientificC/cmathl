#include <stdlib.h>
#include "includes/cml.h"


bool
real_isgreater_or_equals(real x, real y)
{
        return x->isGreater(x, y) || x->equals(x, y);
}
