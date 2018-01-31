#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Back */
real_t
back_ease_in(real_t p)
{
        return p * p * p - p * real_sin(p * PI);
}

real_t
back_ease_out(real_t p)
{
        real_t f = ((1.0) - p);
        return (1.0) - (f * f * f - f * real_sin(f * PI));
}

real_t
back_ease_in_out(real_t p)
{
        real_t f = (0.0);

        if (p < (0.5)) {
                f = (2.0) * p;
                f = (0.5) * (f * f * f - f * real_sin(f * PI));
        } else {
                f = ((1.0) - ((2.0) * p - (1.0)));
                f = (0.5) * ((1.0) - (f * f * f - f * real_sin(f * PI))) + (0.5);
        }

        return f;
}

#endif
