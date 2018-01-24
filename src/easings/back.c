#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Back */
real_t
back_ease_in(real_t p)
{
        return p * p * p - p * real_sin(p * PI);
}

real_t
back_ease_out(real_t p)
{
        real_t f = (MFLOAT_T(1.0) - p);
        return MFLOAT_T(1.0) - (f * f * f - f * real_sin(f * PI));
}

real_t
back_ease_in_out(real_t p)
{
        real_t f = MFLOAT_T(0.0);

        if (p < MFLOAT_T(0.5)) {
                f = MFLOAT_T(2.0) * p;
                f = MFLOAT_T(0.5) * (f * f * f - f * real_sin(f * PI));
        } else {
                f = (MFLOAT_T(1.0) - (MFLOAT_T(2.0) * p - MFLOAT_T(1.0)));
                f = MFLOAT_T(0.5) * (MFLOAT_T(1.0) - (f * f * f - f * real_sin(f * PI))) + MFLOAT_T(0.5);
        }

        return f;
}

#endif
