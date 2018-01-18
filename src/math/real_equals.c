#include <stdlib.h>
#include <cml.h>


CML_EXTERN_INLINE bool
__equals(double x, double y)
{
        return x == y;
}

bool
real_equals(real x, real y)
{
        return __equals(real_value(x), real_value(x));
}
