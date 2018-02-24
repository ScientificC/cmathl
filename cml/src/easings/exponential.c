#include <stdlib.h>
#include <cml/easings.h>
#include <cml/math.h>


/* Easing functions - Exponential */
__CML_EXTERN_INLINE double
cml_ease_exponential_in(double p)
{
        double f = p;

        if (p != 0.0)
        {
                f = cml_pow(2.0, 10.0 * (p - 1.0));
        }

        return f;
}


__CML_EXTERN_INLINE double
cml_ease_exponential_out(double p)
{
        double f = p;

        if (p != 1.0)
        {
                f = 1.0 - cml_pow(2.0, -10.0 * p);
        }

        return f;
}


__CML_EXTERN_INLINE double
cml_ease_exponential_in_out(double p)
{
        double f = p;

        if (p < 0.5)
        {
                f = 0.5 * cml_pow(2.0, (20.0 * p) - 10.0);
        }
        else
        {
                f = -0.5 * cml_pow(2.0, (-20.0 * p) + 10.0) + 1.0;
        }

        return f;
}
