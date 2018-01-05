#include <stdlib.h>
#include <cml.h>


CML_EXTERN_INLINE bool
__isnatural(cml_t x)
{
        return (__isinteger(x) && x > 0);
}

bool
real_isnatural(real x)
{
        return __isnatural(x->value(x));
}
