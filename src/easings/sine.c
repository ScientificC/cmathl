#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Sine */
real
sine_ease_in(real_tp)
{
        real_t f = MFLOAT_T(0.0), f_x, f_p =  p;
        real_tx;

        x = real((f_p - MFLOAT_T(1.0)) * HALFPI);
        f_x =  x;
        f = f_x + MFLOAT_T(1.0);

        

        return real(f);
}

real
sine_ease_out(real_tp)
{
        real_t f = MFLOAT_T(0.0), f_p =  p;
        f = f_p * HALFPI;
        return sin(real(f));
}

real
sine_ease_in_out(real_tp)
{
        real_t c, f_p =  p;

        c =  cos(real(f_p * PI));

        return real(MFLOAT_T(0.5) * (MFLOAT_T(1.0) - c));
}
#endif
