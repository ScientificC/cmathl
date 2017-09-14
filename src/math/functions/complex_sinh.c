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

/*
 * sinh(Z) = (cos(b) * ((e^a - e^-a) / 2) + (sin(b) * (e^a + e^-a) / 2))i
 * sinh(Z) = (cos(b) * cosh(a)) + (sin(b) * sinh(a))i
 *
 * @param complex self
 *
 * @return complex sinh(self)
 *
 */

complex complex_sinh(complex self)
{
        // Declaration of structures
        complex w;
        real *x;
        real k, h, a, b, n, m;

        // Mathematical algorithm
        x = self->parts(self);

        k = x[1]->cos(x[1]);
        h = x[1]->sin(x[1]);
        a = x[0]->sinh(x[0]);
        b = x[0]->cosh(x[0]);

        n = k->prod(k, a);
        m = h->prod(h, b);

        w = complex_new(n, m);

        // Free structures
        free(x);
        free(k);
        free(h);
        free(a);
        free(b);

        // Return
        return w;
}
