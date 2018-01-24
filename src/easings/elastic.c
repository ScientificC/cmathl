#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Elastic */
real_t
elastic_ease_in(real_t p)
{
        return sin(MFLOAT_T(13.0) * HALFPI * p) * pow(MFLOAT_T(2.0), MFLOAT_T(10.0) * (p - MFLOAT_T(1.0)));
}

real_t
elastic_ease_out(real_t p)
{
        return sin(-MFLOAT_T(13.0) * HALFPI * (p + MFLOAT_T(1.0))) * pow(MFLOAT_T(2.0), -MFLOAT_T(10.0) * p) + MFLOAT_T(1.0);
}

real_t
elastic_ease_in_out(real_t p)
{
        real_t f = MFLOAT_T(0.0);

        if (p < MFLOAT_T(0.5)) {
                f = MFLOAT_T(0.5) * sin(MFLOAT_T(13.0) * HALFPI * (MFLOAT_T(2.0) * p)) * pow(MFLOAT_T(2.0), MFLOAT_T(10.0) * ((MFLOAT_T(2.0) * p) - MFLOAT_T(1.0)));
        } else {
                f = MFLOAT_T(0.5) * (sin(-MFLOAT_T(13.0) * HALFPI * ((MFLOAT_T(2.0) * p - MFLOAT_T(1.0)) + MFLOAT_T(1.0))) * pow(MFLOAT_T(2.0), -MFLOAT_T(10.0) * (MFLOAT_T(2.0) * p - MFLOAT_T(1.0))) + MFLOAT_T(2.0));
        }

        return f;
}
#endif
