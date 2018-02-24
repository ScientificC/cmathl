#include <stdlib.h>
#include <cml/easings.h>
#include <cml/math.h>


/* Easing functions - Sine */
__CML_EXTERN_INLINE double
cml_ease_sine_in(double p)
{
        return cml_sin((p - 1.0) * M_PI_2) + 1.0;
}


__CML_EXTERN_INLINE double
cml_ease_sine_out(double p)
{
        return cml_sin(p * M_PI_2);
}


__CML_EXTERN_INLINE double
cml_ease_sine_in_out(double p)
{
        return 0.5 * (1.0 - cml_cos(p * M_PI));
}
