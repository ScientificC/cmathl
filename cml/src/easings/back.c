#include <stdlib.h>
#include <cml/easings.h>
#include <cml/math.h>


/* Easing functions - Back */
__CML_EXTERN_INLINE double
ease_back_in(double p)
{
        return p * p * p - p * real_sin(p * M_PI);
}


__CML_EXTERN_INLINE double
ease_back_out(double p)
{
        double f = 1.0 - p;
        return 1.0 - (f * f * f - f * real_sin(f * M_PI));
}


__CML_EXTERN_INLINE double
ease_back_in_out(double p)
{
        double f = 0.0;

        if (p < 0.5)
        {
                f = 2.0 * p;
                f = 0.5 * (f * f * f - f * real_sin(f * M_PI));
        }
        else
        {
                f = (1.0 - (2.0 * p - 1.0));
                f = 0.5 * (1.0 - (f * f * f - f * real_sin(f * M_PI))) + 0.5;
        }

        return f;
}
