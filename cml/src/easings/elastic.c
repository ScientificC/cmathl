#include <stdlib.h>
#include <cml/easings.h>
#include <cml/math.h>


/* Easing functions - Elastic */
__CML_EXTERN_INLINE double
ease_elastic_in(double p)
{
        return real_sin(13.0 * M_PI_2 * p) * real_pow(2.0, 10.0 * (p - 1.0));
}


__CML_EXTERN_INLINE double
ease_elastic_out(double p)
{
        return real_sin(-13.0 * M_PI_2 * (p + 1.0)) * real_pow(2.0, -10.0 * p) + 1.0;
}


__CML_EXTERN_INLINE double
ease_elastic_in_out(double p)
{
        double f = 0.0;

        if (p < 0.5)
        {
                f = 0.5 * real_sin(13.0 * M_PI_2 * (2.0 * p)) * real_pow(2.0, 10.0 * ((2.0 * p) - 1.0));
        }
        else
        {
                f = 0.5 * (real_sin(-13.0 * M_PI_2 * ((2.0 * p - 1.0) + 1.0)) * real_pow(2.0, -10.0 * (2.0 * p - 1.0)) + 2.0);
        }

        return f;
}
