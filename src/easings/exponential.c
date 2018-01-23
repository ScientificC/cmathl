#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Exponential */
real
exponential_ease_in(real p)
{
        mfloat_t f = MFLOAT_T(0.0), f_p;
        f_p = __mfloat__ p;
        f = f_p;

        if (f_p != MFLOAT_T(0.0)) {
                mfloat_t g = MFLOAT_T(2.0),
                         e = MFLOAT_T(10.0) * (f_p - MFLOAT_T(1.0));

                f = __mfloat__ pow(real(g), real(e));
        }

        return real(f);
}

real
exponential_ease_out(real p)
{
        mfloat_t f = MFLOAT_T(0.0), f_p = __mfloat__ p;

        if (f_p != MFLOAT_T(1.0)) {
                mfloat_t g = MFLOAT_T(2.0),
                         e = -MFLOAT_T(10.0) * f_p;

                f = MFLOAT_T(1.0) - __mfloat__ pow(real(g), real(e));
        }

        return real(f);
}

real
exponential_ease_in_out(real p)
{
        mfloat_t f = MFLOAT_T(0.0), f_p = __mfloat__ p;

        if (f_p < MFLOAT_T(0.5)) {
                f = MFLOAT_T(0.5) * __mfloat__ pow(
                        real(MFLOAT_T(2.0)),
                        real((MFLOAT_T(20.0) * f_p) - MFLOAT_T(10.0))
                        );
        } else {
                f = (-MFLOAT_T(0.5) * (
                             __mfloat__ pow(
                                     real(MFLOAT_T(2.0)),
                                     real((-MFLOAT_T(20.0) * f_p) + MFLOAT_T(10.0)))
                             )
                     ) + MFLOAT_T(1.0);
        }

        return real(f);
}
#endif
