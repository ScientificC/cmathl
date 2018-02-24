#include <stdlib.h>
#include <cml/easings.h>
#include <cml/math.h>


/* Easing functions - Quadratic  */
__CML_EXTERN_INLINE double
ease_quadratic_in(double p)
{
        return p * p;
}


__CML_EXTERN_INLINE double
ease_quadratic_out(double p)
{
        return -(p * (p - 2.0));
}


__CML_EXTERN_INLINE double
ease_quadratic_in_out(double p)
{
        double f = 0.0;

        if (p < 0.5)
        {
                f = 2.0 * p * p;
        }
        else
        {
                f = (-2.0 * p * p) + (4.0 * p) - 1.0;
        }

        return f;
}
