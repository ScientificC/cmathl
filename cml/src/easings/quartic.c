#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Quartic */
real_t
quartic_ease_in(real_t p)
{
        return p * p * p * p;
}

real_t
quartic_ease_out(real_t p)
{
        real_t f = (p - (1.0));
        return f * f * f * ((1.0) - p) + (1.0);
}

real_t
quartic_ease_in_out(real_t p)
{
        real_t f = (0.0);

        if (p < (0.5)) {
                f = (8.0) * p * p * p * p;
        } else {
                f = (p - (1.0));
                f = -(8.0) * f * f * f * f + (1.0);
        }

        return f;
}
#endif
