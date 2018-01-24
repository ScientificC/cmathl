#include <stdlib.h>
#include <cml.h>

real_t
real_sgn(real_t x)
{
        return (real_t) MFLOAT_T(x >= 0.0 ? 1.0 : -1.0);
}
