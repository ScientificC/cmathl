#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Sine */
real
sine_ease_in(real p)
{
        mfloat_t f = MFLOAT_T(0.0), f_x, f_p = __mfloat__ p;
        real x;

        x = real((f_p - MFLOAT_T(1.0)) * HALFPI);
        f_x = __mfloat__ x;
        f = f_x + MFLOAT_T(1.0);

        free(x);

        return real(f);
}

real
sine_ease_out(real p)
{
        mfloat_t f = MFLOAT_T(0.0), f_p = __mfloat__ p;
        f = f_p * HALFPI;
        return sin(real(f));
}

real
sine_ease_in_out(real p)
{
        mfloat_t c, f_p = __mfloat__ p;

        c = __mfloat__ cos(real(f_p * PI));

        return real(MFLOAT_T(0.5) * (MFLOAT_T(1.0) - c));
}
#endif
