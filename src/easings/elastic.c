#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Elastic */
real
elastic_ease_in(real_tp)
{
        real_t f_p =  p;

        return prod(
                sin(real(MFLOAT_T(13.0) * HALFPI * f_p)),
                pow(
                        real(MFLOAT_T(2.0)),
                        real(MFLOAT_T(10.0) * (f_p - MFLOAT_T(1.0)))
                        )
                );
}

real
elastic_ease_out(real_tp)
{
        real_t f_p =  p;

        return real(MFLOAT_T(1.0) +
                     sin(
                            prod(real(-MFLOAT_T(13.0) * HALFPI
                                      * (f_p + MFLOAT_T(1.0))), pow(
                                         real(MFLOAT_T(2.0)),
                                         real(-MFLOAT_T(10.0) * f_p))

                                 ))
                    );
}

real
elastic_ease_in_out(real_tp)
{
        real_t f = MFLOAT_T(0.0), f_p =  p;

        if (f_p < MFLOAT_T(0.5)) {
                f = MFLOAT_T(0.5) *  sin(real(MFLOAT_T(13.0) * HALFPI * (MFLOAT_T(2.0) * f_p))) *  pow(real(MFLOAT_T(2.0)), real(MFLOAT_T(10.0) * ((MFLOAT_T(2.0) * f_p) - MFLOAT_T(1.0))));
        } else {
                f = ( pow(real(MFLOAT_T(2.0)), real(-MFLOAT_T(10.0) * (MFLOAT_T(2.0) * f_p - MFLOAT_T(1.0)))));
                f = MFLOAT_T(0.5) * ( sin(real(-MFLOAT_T(13.0) * HALFPI * ((MFLOAT_T(2.0) * f_p - MFLOAT_T(1.0)) + MFLOAT_T(1.0)))) * f + MFLOAT_T(2.0));
        }

        return real(f);
}
#endif
