/* Copyright (C) 2017 CMATHL

   This file is part of CML.

   CML is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   CML is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with CML. If not, see <http://www.gnu.org/licenses/>.     */

#include <stdlib.h>
#include "../../../includes/cml.h"

complex complex_csc(complex self)
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
