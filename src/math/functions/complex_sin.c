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
 * sin(Z) = (sin(a) * ((e^b + e^-b) / 2) + (Cos(a) * (e^b - e^-b) / 2))i
 * sin(Z) = (sin(a) * cosh(b)) + (cos(a) * sinh(b))i
 *
 * @param complex self
 *
 * @return complex sin(self)
 *
 */

complex complex_sin(complex self)
{
        // Declaration of structures
        complex w;
        real *x;
        real k, h, a, b, n, m;

        // Mathematical algorithm
        x = self->parts(self);

        k = x[0]->sin(x[0]);
        h = x[0]->cos(x[0]);
        a = x[1]->cosh(x[1]);
        b = x[1]->sinh(x[1]);

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
