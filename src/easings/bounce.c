#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Bounce */
real_t
bounce_ease_in(real_t p)
{
        return MFLOAT_T(1.0) - bounce_ease_out(MFLOAT_T(1.0) - p);
}

real_t
bounce_ease_out(real_t p)
{
        real_t f = MFLOAT_T(0.0);

        if (p < MFLOAT_T(4.0) / MFLOAT_T(11.0)) {
                f = (MFLOAT_T(121.0) * p * p) / MFLOAT_T(16.0);
        } else if (p < MFLOAT_T(8.0) / MFLOAT_T(11.0)) {
                f = (MFLOAT_T(363.0) / MFLOAT_T(40.0) * p * p) - (MFLOAT_T(99.0) / MFLOAT_T(10.0) * p) + MFLOAT_T(17.0) / MFLOAT_T(5.0);
        } else if (p < MFLOAT_T(9.0) / MFLOAT_T(10.0)) {
                f = (MFLOAT_T(4356.0) / MFLOAT_T(361.0) * p * p) - (MFLOAT_T(35442.0) / MFLOAT_T(1805.0) * p) + MFLOAT_T(16061.0) / MFLOAT_T(1805.0);
        } else {
                f = (MFLOAT_T(54.0) / MFLOAT_T(5.0) * p * p) - (MFLOAT_T(513.0) / MFLOAT_T(25.0) * p) + MFLOAT_T(268.0) / MFLOAT_T(25.0);
        }

        return f;
}

real_t
bounce_ease_in_out(real_t p)
{
        real_t f = MFLOAT_T(0.0);

        if (p < MFLOAT_T(0.5)) {
                f = MFLOAT_T(0.5) * bounce_ease_in(p * MFLOAT_T(2.0));
        } else {
                f = MFLOAT_T(0.5) * bounce_ease_out(p * MFLOAT_T(2.0) - MFLOAT_T(1.0)) + MFLOAT_T(0.5);
        }

        return f;
}
#endif
