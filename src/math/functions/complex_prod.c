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
 * (a + bi) · (c + di) = (ac − bd) + (ad + bc)i
 *
 */

complex complex_prod(complex self, complex z)
{
        // Declaration of structures
        complex w;
        real n, m;
        real *x, *y;
        double a, b, c, d;

        // Mathematic algorithm
        x = self->parts(self);
        y = z->parts(z);

        a = x[0]->value(x[0]);
        b = x[1]->value(x[1]);
        c = y[0]->value(y[0]);
        d = y[1]->value(y[1]);

        n = real_new(a*c - b*d);
        m = real_new(a*d + b*c);

        w = complex_new(n, m);

        // Free structures
        free(x);
        free(y);

        // Return
        return w;
}
