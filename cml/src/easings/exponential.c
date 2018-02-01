#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Exponential */
real_t
exponential_ease_in(real_t p)
{
        real_t f = p;

        if (p != 0.0) {
                f = real_pow(2.0, 10.0 * (p - 1.0));
        }

        return f;
}

real_t
exponential_ease_out(real_t p)
{
        real_t f = p;

        if (p != 1.0) {
                f = 1.0 - real_pow(2.0, -10.0 * p);
        }

        return f;
}

real_t
exponential_ease_in_out(real_t p)
{
        real_t f = p;

        if (p < 0.5) {
                f = 0.5 * real_pow(2.0, (20.0 * p) - 10.0);
        } else {
                f = -0.5 * real_pow(2.0, (-20.0 * p) + 10.0) + 1.0;
        }

        return f;
}
#endif
