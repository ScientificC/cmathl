#include <stdlib.h>
#include "../../../includes/cml.h"

complex
complex_csc(complex self)
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
        complex w;

        // Mathematical algorithm
        w = s->inverse(s);

        // Free structures
        free(s);

        // Return
        return w;
}
