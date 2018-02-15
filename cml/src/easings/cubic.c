#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Cubic */
__CML_EXTERN_INLINE real_t
ease_cubic_in(real_t p)
{
        return p * p * p;
}

__CML_EXTERN_INLINE real_t
ease_cubic_out(real_t p)
{
        real_t f = (p - 1.0);
        return f * f * f + 1.0;
}

__CML_EXTERN_INLINE real_t
ease_cubic_in_out(real_t p)
{
        real_t f = 0.0;
        if (p < 0.5)
        {
                f = 4.0 * p * p * p;
        }
        else
        {
                f = ((2.0 * p) - 2.0);
                f = 0.5 * f * f * f + 1.0;
        }
        return f;
}
#endif
