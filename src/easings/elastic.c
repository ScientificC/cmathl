#include <stdlib.h>
#include <cml.h>

#ifndef CML_NO_EASING_FUNCTIONS
/* Easing functions - Elastic */
real_t
elastic_ease_in(real_t p)
{
        return sin((13.0) * HALFPI * p) * pow((2.0), (10.0) * (p - (1.0)));
}

real_t
elastic_ease_out(real_t p)
{
        return sin(-(13.0) * HALFPI * (p + (1.0))) * pow((2.0), -(10.0) * p) + (1.0);
}

real_t
elastic_ease_in_out(real_t p)
{
        real_t f = (0.0);

        if (p < (0.5)) {
                f = (0.5) * sin((13.0) * HALFPI * ((2.0) * p)) * pow((2.0), (10.0) * (((2.0) * p) - (1.0)));
        } else {
                f = (0.5) * (sin(-(13.0) * HALFPI * (((2.0) * p - (1.0)) + (1.0))) * pow((2.0), -(10.0) * ((2.0) * p - (1.0))) + (2.0));
        }

        return f;
}
#endif
