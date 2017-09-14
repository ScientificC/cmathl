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
 * (a + bi) + (c + di) = (a+c) + (b+d)i
 *
 */

complex complex_add(complex self, complex z)
{
        // Declaration of structures
        complex w;
        real n, m, *x, *y;

        // Mathematical algorithm
        x = self->parts(self);
        y = z->parts(z);
        n = x[0]->add(x[0], y[0]);
        m = x[1]->add(x[1], y[1]);
        w = complex_new(n, m);

        // Free structures
        free(x);
        free(y);

        // Return
        return w;
}
