#include <stdlib.h>
#include <cml.h>


CML_EXTERN_INLINE bool
__isgreater(cml_t x, cml_t y)
{
        return x > y;
}

bool
real_isgreater(real x, real y)
{
        return __isgreater(x->value(x), y->value(y));
}
