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
 * Hyperbolic sine "real_sinh(x)" function developed by using Euler relationships
 *
 * @param real x
 *
 * @return real real_sinh(x)
 */

real real_sinh(real x)
{
        // Domain check

        // Declaration of variables and structures
        real y, z, w, k, c, h;

        // Mathematic algorithm
        c = real_new(2.0);
        y = x->opposite(x);
        z = x->exp(x);
        w = y->exp(y);
        k = z->sub(z, w);
        h = z->div(z, c);

        // Free structures
        free(y);
        free(z);
        free(w);
        free(k);
        free(c);

        // Return
        return h;
}
