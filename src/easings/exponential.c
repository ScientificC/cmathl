#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Exponential */
real_t
exponential_ease_in(real_t p)
{
        real_t f = p;

        if (p != MFLOAT_T(0.0)) {
                f = real_pow(MFLOAT_T(2.0), MFLOAT_T(10.0) * (p - MFLOAT_T(1.0)));
        }

        return f;
}

real_t
exponential_ease_out(real_t p)
{
        real_t f = p;

        if (p != MFLOAT_T(1.0)) {
                f = MFLOAT_T(1.0) - real_pow(MFLOAT_T(2.0), -MFLOAT_T(10.0) * p);
        }

        return f;
}

real_t
exponential_ease_in_out(real_t p)
{
        real_t f = p;

        if (p < MFLOAT_T(0.5)) {
                f = MFLOAT_T(0.5) * real_pow(MFLOAT_T(2.0), (MFLOAT_T(20.0) * p) - MFLOAT_T(10.0));
        } else {
                f = -MFLOAT_T(0.5) * real_pow(MFLOAT_T(2.0), (-MFLOAT_T(20.0) * p) + MFLOAT_T(10.0)) + MFLOAT_T(1.0);
        }

        return f;
}
#endif
