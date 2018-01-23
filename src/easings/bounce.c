#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Bounce */
real
bounce_ease_in(real p)
{
        mfloat_t f = MFLOAT_T(0.0), f_p = __mfloat__ p;
        f = __mfloat__ (bounce_ease_out(real(MFLOAT_T(1.0) - f_p)));
        return real(MFLOAT_T(1.0) - f);
}

real
bounce_ease_out(real p)
{
        mfloat_t f = MFLOAT_T(0.0), f_p = __mfloat__ p;

        if (f_p < MFLOAT_T(4.0) / MFLOAT_T(11.0)) {
                f = (MFLOAT_T(121.0) * f_p * f_p) / MFLOAT_T(16.0);
        } else if (f_p < MFLOAT_T(8.0) / MFLOAT_T(11.0)) {
                f = (MFLOAT_T(363.0) / MFLOAT_T(40.0) * f_p * f_p) - (MFLOAT_T(99.0) / MFLOAT_T(10.0) * f_p) + MFLOAT_T(17.0) / MFLOAT_T(5.0);
        } else if (f_p < MFLOAT_T(9.0) / MFLOAT_T(10.0)) {
                f = (MFLOAT_T(4356.0) / MFLOAT_T(361.0) * f_p * f_p) - (MFLOAT_T(35442.0) / MFLOAT_T(1805.0) * f_p) + MFLOAT_T(16061.0) / MFLOAT_T(1805.0);
        } else {
                f = (MFLOAT_T(54.0) / MFLOAT_T(5.0) * f_p * f_p) - (MFLOAT_T(513.0) / MFLOAT_T(25.0) * f_p) + MFLOAT_T(268.0) / MFLOAT_T(25.0);
        }

        return real(f);
}

real
bounce_ease_in_out(real p)
{
        mfloat_t f = MFLOAT_T(0.0), f_p = __mfloat__ p;

        if (f_p < MFLOAT_T(0.5)) {
                f = MFLOAT_T(0.5) * __mfloat__ (bounce_ease_in(real(f_p * MFLOAT_T(2.0))));
        } else {
                f = MFLOAT_T(0.5) * __mfloat__ (bounce_ease_out(real(f_p * MFLOAT_T(2.0) - MFLOAT_T(1.0)))) + MFLOAT_T(0.5);
        }

        return real(f);
}
#endif
