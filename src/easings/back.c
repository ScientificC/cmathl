#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Back */
real
back_ease_in(real_tp)
{
        real_t f, g,  f_p =  p;
        real_tx, y;
        x = real(f_p * PI);
        y = sin(x);
        g =  y;
        f = f_p * f_p * f_p - f_p * g;

        
        

        return real(f);
}

real
back_ease_out(real_tp)
{
        real_t g, f = (MFLOAT_T(1.0) -  p);
        real_tx, y;

        x = real(f * PI);
        y = sin(x);
        g =  y;

        
        

        return real(MFLOAT_T(1.0) - (f * f * f - f * g));
}

real
back_ease_in_out(real_tp)
{
        real_t g, f = MFLOAT_T(0.0), f_p =  p;
        real_tx, y;

        x = real(f * PI);
        y = sin(x);
        g =  y;

        if (f_p < MFLOAT_T(0.5)) {
                f = MFLOAT_T(2.0) * f_p;
                f = MFLOAT_T(0.5) * (f * f * f - f * g);
        } else {
                f = (MFLOAT_T(1.0) - (MFLOAT_T(2.0) * f_p - MFLOAT_T(1.0)));
                f = MFLOAT_T(0.5) * (MFLOAT_T(1.0) - (f * f * f - f * g)) + MFLOAT_T(0.5);
        }

        
        

        return real(f);
}
#endif
