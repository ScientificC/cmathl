#include <stdlib.h>
#include <cml.h>


/* Easing functions - Quartic */
__CML_EXTERN_INLINE double
ease_quartic_in(double p)
{
        return p * p * p * p;
}


__CML_EXTERN_INLINE double
ease_quartic_out(double p)
{
        double f = (p - 1.0);
        return f * f * f * (1.0 - p) + 1.0;
}


__CML_EXTERN_INLINE double
ease_quartic_in_out(double p)
{
        double f = 0.0;

        if (p < 0.5)
        {
                f = 8.0 * p * p * p * p;
        }
        else
        {
                f = (p - 1.0);
                f = -8.0 * f * f * f * f + 1.0;
        }

        return f;
}
