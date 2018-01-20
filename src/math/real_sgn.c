#include <stdlib.h>
#include <cml.h>

real
real_sgn(real x)
{
        mint_t sgn;
        sgn = real_value(x) >= 0 ? 1 : -1;
        return real_new(sgn);
}
