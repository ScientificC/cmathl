#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Sine */
real_t
sine_ease_in(real_t p)
{
        return real_sin((p - MFLOAT_T(1.0)) * HALFPI) + MFLOAT_T(1.0);
}

real_t
sine_ease_out(real_t p)
{
        return real_sin(p * HALFPI);
}

real_t
sine_ease_in_out(real_t p)
{
        return MFLOAT_T(0.5) * (MFLOAT_T(1.0) - real_cos(p * PI));
}
#endif
