#include <stdlib.h>
#include <cml.h>


CML_EXTERN_INLINE bool
__isless(cml_t x, cml_t y)
{
        return x < y;
}

bool
real_isless(real x, real y)
{
        return __isless(x->value(x), y->value(y));
}
