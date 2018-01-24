#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Quintic */
real_t
quintic_ease_in(real_t p)
{
        return p * p * p * p * p;
}

real_t
quintic_ease_out(real_t p)
{
        real_t f = (p - MFLOAT_T(1.0));
        return f * f * f * f * f + MFLOAT_T(1.0);
}

real_t
quintic_ease_in_out(real_t p)
{
        real_t f = MFLOAT_T(0.0);

        if (p < MFLOAT_T(0.5)) {
                f = MFLOAT_T(16.0) * p * p * p * p * p;
        } else {
                f = ((MFLOAT_T(2.0) * p) - MFLOAT_T(2.0));
                f = MFLOAT_T(0.5) * f * f * f * f * f + MFLOAT_T(1.0);
        }

        return f;
}
#endif
