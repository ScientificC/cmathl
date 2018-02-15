#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Sine */
__CML_EXTERN_INLINE real_t
ease_sine_in(real_t p)
{
        return real_sin((p - 1.0) * M_PI_2) + 1.0;
}

__CML_EXTERN_INLINE real_t
ease_sine_out(real_t p)
{
        return real_sin(p * M_PI_2);
}

__CML_EXTERN_INLINE real_t
ease_sine_in_out(real_t p)
{
        return 0.5 * (1.0 - real_cos(p * M_PI));
}
#endif
