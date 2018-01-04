#include <stdlib.h>
#include "include/math.h"

complex
complex_tan(complex self)
{
        // Domain check
        complex c = self->cos(self);
        real a = c->abs(c);
        if (!a->isNull(a)) {
                free(a);
                free(c);
                return complex_new(real_new(NAN), real_new(NAN));
        }
        free(a);

        // Declaration of structures
        complex s, w;

        // Mathematical algorithm
        s = self->sin(self);
        w = s->div(s, c);

        // Free structures
        free(s);
        free(c);

        // Return
        return w;
}
