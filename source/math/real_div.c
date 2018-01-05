#include <stdlib.h>
#include <cml.h>

real
real_div(real x, real y)
{
        cml_t k, w;
        k = x->value(x);
        w = y->value(y);
        return real_new((cml_t) k/w);
}
