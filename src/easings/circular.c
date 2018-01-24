#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Circular */
real
circular_ease_in(real_tp)
{
        real_t c, f, f_p =  p;

        f = MFLOAT_T(1.0) - (f_p * f_p);
        c =  sqrt(real(f));

        return real(MFLOAT_T(1.0) - c);
}

real
circular_ease_out(real_tp)
{
        real_t f_p =  p;
        return sqrt(real((MFLOAT_T(2.0) - f_p) * f_p));
}

real
circular_ease_in_out(real_tp)
{
        real_t f = MFLOAT_T(0.0), g, f_p =  p;

        if (f_p < MFLOAT_T(0.5)) {
                g = MFLOAT_T(1.0) - MFLOAT_T(4.0) * (f_p * f_p);
                f = MFLOAT_T(0.5) * (MFLOAT_T(1.0) -  sqrt(real(g)));
        } else {
                g = -((MFLOAT_T(2.0) * f_p) - MFLOAT_T(3.0)) * ((MFLOAT_T(2.0) * f_p) - MFLOAT_T(1.0));
                f = MFLOAT_T(0.5) * (( sqrt(real(g))) + MFLOAT_T(1.0));
        }

        return real(f);
}
#endif
