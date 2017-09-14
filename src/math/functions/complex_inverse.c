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
 * It can be shown that, let z = a + bi a complex number, the multiplicative inverse of z (w), with a⋅b ≠ 0, is
 * W = conjugate(z) / abs(z)^2
 *
 */

complex complex_inverse(complex self)
{
        // Declaration of structures
        complex z, h;
        real *x;
        real a, b, i, m, n;


        // Mathematical algorithm
        z = self->conjugate(self);
        x = z->parts(z);
        a = self->abs(self);
        i = real_new(2.0);
        b = a->pow(a, i);
        n = x[0]->div(x[0], b);
        m = x[1]->div(x[1], b);

        h = complex_new(n, m);

        // Free structures
        free(z);
        free(x);
        free(a);
        free(b);
        free(i);

        // Return
        return h;
}
