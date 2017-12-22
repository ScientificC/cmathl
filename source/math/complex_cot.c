#include <stdlib.h>
#include "includes/cml.h"

complex
complex_cot(complex self)
{
        // Domain check
        complex s = self->sin(self);
        real a = s->abs(s);
        if (!a->isNull(a)) {
                free(a);
                free(s);
                return complex_new(real_new(NAN), real_new(NAN));
        }
        free(a);

        // Declaration of structures
        complex c, w;

        // Mathematical algorithm
        c = self->cos(self);
        w = s->div(c, s);

        // Free structures
        free(c);
        free(s);

        // Return
        return w;
}
