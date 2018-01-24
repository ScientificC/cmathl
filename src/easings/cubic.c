#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Cubic */
real
cubic_ease_in(real_tp)
{
        real_t f_p =  p;

        return real(f_p * f_p * f_p);
}

real
cubic_ease_out(real_tp)
{
        real_t f_p, f;

        f_p =  p;
        f = (f_p - MFLOAT_T(1.0));

        return real(f * f * f + MFLOAT_T(1.0));
}

real
cubic_ease_in_out(real_tp)
{
        real_t f_p, f;
        f_p =  p;
        f = MFLOAT_T(0.0);

        if (f_p < MFLOAT_T(0.5)) {
                f = MFLOAT_T(4.0) * f_p * f_p * f_p;
        } else {
                f = ((MFLOAT_T(2.0) * f_p) - MFLOAT_T(2.0));
                f = MFLOAT_T(0.5) * f * f * f + MFLOAT_T(1.0);
        }

        return real(f);
}
#endif
