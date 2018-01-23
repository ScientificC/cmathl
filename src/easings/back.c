#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Back */
real
back_ease_in(real p)
{
        mfloat_t f_p = __mfloat__ p;
        return real(f_p * f_p * f_p - f_p * __mfloat__ sin(real(f_p * PI)));
}

real
back_ease_out(real p)
{
        mfloat_t f = (MFLOAT_T(1.0) - __mfloat__ p);
        return real(MFLOAT_T(1.0) - (f * f * f - f * __mfloat__ sin(real(f * PI))));
}

real
back_ease_in_out(real p)
{
        mfloat_t f = MFLOAT_T(0.0), f_p = __mfloat__ p;

        if (f_p < MFLOAT_T(0.5)) {
                f = MFLOAT_T(2.0) * f_p;
                f = MFLOAT_T(0.5) * (f * f * f - f * __mfloat__ sin(real(f * PI)));
        } else {
                f = (MFLOAT_T(1.0) - (MFLOAT_T(2.0) * f_p - MFLOAT_T(1.0)));
                f = MFLOAT_T(0.5) * (MFLOAT_T(1.0) - (f * f * f - f * __mfloat__ sin(real(f * PI)))) + MFLOAT_T(0.5);
        }

        return real(f);
}
#endif
