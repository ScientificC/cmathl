#include <stdlib.h>
#include <cml/easings.h>
#include <cml/math.h>


/* Easing functions - Quintic */
__CML_EXTERN_INLINE double
cml_ease_quintic_in(double p)
{
        return p * p * p * p * p;
}


__CML_EXTERN_INLINE double
cml_ease_quintic_out(double p)
{
        double f = p - 1.0;
        return f * f * f * f * f + 1.0;
}


__CML_EXTERN_INLINE double
cml_ease_quintic_in_out(double p)
{
        double f = 0.0;

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
