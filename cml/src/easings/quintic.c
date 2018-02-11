#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Quintic */
real_t
ease_quintic_in(real_t p)
{
        return p * p * p * p * p;
}

real_t
ease_quintic_out(real_t p)
{
        real_t f = p - 1.0;
        return f * f * f * f * f + 1.0;
}

real_t
ease_quintic_in_out(real_t p)
{
        real_t f = 0.0;

        if (p < 0.5)
        {
                f = 16.0 * p * p * p * p * p;
        }
        else
        {
                f = ((2.0 * p) - 2.0);
                f = 0.5 * f * f * f * f * f + 1.0;
        }

        return f;
}
#endif
