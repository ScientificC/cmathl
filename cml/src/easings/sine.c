#include <stdlib.h>
#include <cml.h>


/* Easing functions - Sine */
__CML_EXTERN_INLINE double
ease_sine_in(double p)
{
        return real_sin((p - 1.0) * M_PI_2) + 1.0;
}


__CML_EXTERN_INLINE double
ease_sine_out(double p)
{
        return real_sin(p * M_PI_2);
}


__CML_EXTERN_INLINE double
ease_sine_in_out(double p)
{
        return 0.5 * (1.0 - real_cos(p * M_PI));
}
