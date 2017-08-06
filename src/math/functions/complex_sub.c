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

complex complex_sub(complex self, complex z)
{
        // Declaration of structures
        complex h, w;
        real n, m, *x;

        // Mathematical algorithm
        x = z->parts(z);
        n = x[0]->opposite(x[0]);
        m = x[1]->opposite(x[1]);
        w = complex_new(n, m);

        h = self->add(self, w);

        // Free structures
        free(x);
        free(n);
        free(m);
        free(w);

        // Return
        return h;
}
