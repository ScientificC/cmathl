#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Sine */
real_t
sine_ease_in(real_t p)
{
        return sin((p - (1.0)) * HALFPI) + (1.0);
}

real_t
sine_ease_out(real_t p)
{
        return sin(p * HALFPI);
}

real_t
sine_ease_in_out(real_t p)
{
        return (0.5) * ((1.0) - cos(p * PI));
}
#endif
