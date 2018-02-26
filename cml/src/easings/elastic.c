#include <stdlib.h>
#include <cml/easings.h>
#include <cml/math.h>


/* Easing functions - Elastic */
__CML_EXTERN_INLINE double
cml_ease_elastic_in(double p)
{
        return cml_sin(13.0 * M_PI_2 * p) * cml_pow(2.0, 10.0 * (p - 1.0));
}


__CML_EXTERN_INLINE double
cml_ease_elastic_out(double p)
{
        return cml_sin(-13.0 * M_PI_2 * (p + 1.0)) * cml_pow(2.0, -10.0 * p) + 1.0;
}


__CML_EXTERN_INLINE double
cml_ease_elastic_in_out(double p)
{
        double f = 0.0;

        if (p < 0.5)
        {
                f = 0.5 * cml_sin(13.0 * M_PI_2 * (2.0 * p)) * cml_pow(2.0, 10.0 * ((2.0 * p) - 1.0));
        }
        else
        {
                f = 0.5 * (cml_sin(-13.0 * M_PI_2 * ((2.0 * p - 1.0) + 1.0)) * cml_pow(2.0, -10.0 * (2.0 * p - 1.0)) + 2.0);
        }

        return f;
}
