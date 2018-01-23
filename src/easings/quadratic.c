#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Quadratic  */
real
quadratic_ease_in(real p)
{
        mfloat_t f_p = __mfloat__ p;
        return real(f_p * f_p);
}

real
quadratic_ease_out(real p)
{
        mfloat_t f_p = __mfloat__ p;
        return real(-(f_p * (f_p - MFLOAT_T(2.0))));
}

real
quadratic_ease_in_out(real p)
{
        mfloat_t f = MFLOAT_T(0.0), f_p = __mfloat__ p;

        if (f_p < MFLOAT_T(0.5)) {
                f = MFLOAT_T(2.0) * f_p * f_p;
        } else {
                f = (-MFLOAT_T(2.0) * f_p * f_p) + (MFLOAT_T(4.0) * f_p) - MFLOAT_T(1.0);
        }

        return real(f);
}
#endif
