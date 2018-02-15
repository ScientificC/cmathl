#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Quadratic  */
__CML_EXTERN_INLINE real_t
ease_quadratic_in(real_t p)
{
        return p * p;
}

__CML_EXTERN_INLINE real_t
ease_quadratic_out(real_t p)
{
        return -(p * (p - 2.0));
}

__CML_EXTERN_INLINE real_t
ease_quadratic_in_out(real_t p)
{
        real_t f = 0.0;

        if (p < 0.5)
        {
                f = 2.0 * p * p;
        }
        else
        {
                f = (-2.0 * p * p) + (4.0 * p) - 1.0;
        }

        return f;
}
#endif
