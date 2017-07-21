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

#include "../../../includes/cml.h"

/*
 * exp(Z) = e^Z = (e^a * Cos(b) + e^a * Sin(b)i)
 *
 * @param complex z: Exponent of the function
 *
 * @return complex e^z
 *
 */

complex complex_exp(complex self)
{
        // Declaration of structures
        complex w;
        real *p;
        real n, m, h, x, y;

        // Mathematic algorithm
        p = self->parts(self);
        h = p[0]->exp(p[0]);
        n = p[1]->cos(p[1]);
        m = p[1]->sin(p[1]);
        x = h->prod(h, n);
        y = h->prod(h, m);

        w = complex_new(x, y);

        // Free structures
        free(p);
        free(n);
        free(m);
        free(h);

        // Return
        return w;
}
