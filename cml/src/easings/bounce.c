#include <stdlib.h>
#include <cml/easings.h>
#include <cml/math.h>


/* Easing functions - Bounce */
__CML_EXTERN_INLINE double
cml_ease_bounce_in(double p)
{
        return 1.0 - cml_ease_bounce_out(1.0 - p);
}


__CML_EXTERN_INLINE double
cml_ease_bounce_out(double p)
{
        double f = (0.0);

        if (p < 4.0/11.0)
        {
                f = (121.0 * p * p)/16.0;
        }
        else if (p < 8.0/11.0)
        {
                f = (363.0/40.0 * p * p) - (99.0/10.0 * p) + 17.0/5.0;
        }
        else if (p < 9.0/10.0)
        {
                f = (4356.0/361.0 * p * p) - (35442.0/1805.0 * p) + 16061.0/1805.0;
        }
        else
        {
                f = (54.0/5.0 * p * p) - (513.0/25.0 * p) + 268.0/25.0;
        }

        return f;
}


__CML_EXTERN_INLINE double
cml_ease_bounce_in_out(double p)
{
        double f = 0.0;

        if (p < 0.5)
        {
                f = 0.5 * cml_ease_bounce_in(p * 2.0);
        }
        else
        {
                f = 0.5 * cml_ease_bounce_out(p * 2.0 - 1.0) + 0.5;
        }

        return f;
}
