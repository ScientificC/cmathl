#include <stdlib.h>
#include <cml.h>

real
real_sub(real x, real y)
{
        mfloat_t k, w;

        k = real_value(x);
        w = real_value(y);

        return real_new((mfloat_t) k-w);
}
