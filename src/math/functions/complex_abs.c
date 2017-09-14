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

real complex_abs(complex self)
{
        // Declaration of structures
        real *x;
        real n, a, b, w, h;


        // Mathematical algorithm
        x = self->parts(self);
        n = real_new(2.0);
        a = x[0]->pow(x[0], n);
        b = x[1]->pow(x[1], n);
        w = a->add(a, b);
        h = w->sqrt(w);

        // Free structures
        free(x);
        free(n);
        free(a);
        free(b);
        free(w);

        // Return
        return h;
}
