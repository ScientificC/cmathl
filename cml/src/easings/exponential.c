#include <stdlib.h>
#include <cml.h>


/* Easing functions - Exponential */
__CML_EXTERN_INLINE double
ease_exponential_in(double p)
{
        double f = p;

        if (p != 0.0)
        {
                f = real_pow(2.0, 10.0 * (p - 1.0));
        }

        return f;
}


__CML_EXTERN_INLINE double
ease_exponential_out(double p)
{
        double f = p;

        if (p != 1.0)
        {
                f = 1.0 - real_pow(2.0, -10.0 * p);
        }

        return f;
}


__CML_EXTERN_INLINE double
ease_exponential_in_out(double p)
{
        double f = p;

        if (p < 0.5)
        {
                f = 0.5 * real_pow(2.0, (20.0 * p) - 10.0);
        }
        else
        {
                f = -0.5 * real_pow(2.0, (-20.0 * p) + 10.0) + 1.0;
        }

        return f;
}
