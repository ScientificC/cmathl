#include <stdlib.h>
#include <cml/easings.h>
#include <cml/math.h>


/* Easing functions - Cubic */
__CML_EXTERN_INLINE double
ease_cubic_in(double p)
{
        return p * p * p;
}


__CML_EXTERN_INLINE double
ease_cubic_out(double p)
{
        double f = (p - 1.0);
        return f * f * f + 1.0;
}


__CML_EXTERN_INLINE double
ease_cubic_in_out(double p)
{
        double f = 0.0;
        if (p < 0.5)
        {
                f = 4.0 * p * p * p;
        }
        else
        {
                f = ((2.0 * p) - 2.0);
                f = 0.5 * f * f * f + 1.0;
        }
        return f;
}
