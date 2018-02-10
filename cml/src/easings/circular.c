#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Circular */
real_t
circular_ease_in(real_t p)
{
        return 1.0 - real_sqrt(1.0 - (p * p));
}

real_t
circular_ease_out(real_t p)
{
        return real_sqrt((2.0 - p) * p);
}

real_t
circular_ease_in_out(real_t p)
{
        real_t f = 0.0;

        if (p < 0.5)
        {
                f = 0.5 * (1.0 - real_sqrt(1.0 - 4.0 * p * p));
        }
        else
        {
                f = 0.5 * (real_sqrt(-((2.0 * p) - 3.0) * ((2.0 * p) - 1.0)) + 1.0);
        }

        return f;
}
#endif
