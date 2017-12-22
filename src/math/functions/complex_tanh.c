#include <stdlib.h>
#include "../../../includes/cml.h"

complex
complex_tanh(complex self)
{
        // Domain check
        complex c = self->cosh(self);
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
        s = self->sinh(self);
        w = s->div(s, c);

        // Free structures
        free(s);
        free(c);

        // Return
        return w;
}
