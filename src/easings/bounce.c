#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Bounce */
real_t
bounce_ease_in(real_t p)
{
        return (1.0) - bounce_ease_out((1.0) - p);
}

real_t
bounce_ease_out(real_t p)
{
        real_t f = (0.0);

        if (p < (4.0) / (11.0)) {
                f = ((121.0) * p * p) / (16.0);
        } else if (p < (8.0) / (11.0)) {
                f = ((363.0) / (40.0) * p * p) - ((99.0) / (10.0) * p) + (17.0) / (5.0);
        } else if (p < (9.0) / (10.0)) {
                f = ((4356.0) / (361.0) * p * p) - ((35442.0) / (1805.0) * p) + (16061.0) / (1805.0);
        } else {
                f = ((54.0) / (5.0) * p * p) - ((513.0) / (25.0) * p) + (268.0) / (25.0);
        }

        return f;
}

real_t
bounce_ease_in_out(real_t p)
{
        real_t f = (0.0);

        if (p < (0.5)) {
                f = (0.5) * bounce_ease_in(p * (2.0));
        } else {
                f = (0.5) * bounce_ease_out(p * (2.0) - (1.0)) + (0.5);
        }

        return f;
}
#endif
