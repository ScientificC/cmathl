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
 * Hyperbolic tangent "tanh(x)" function developed by using Euler relationships
 *
 * @param real x
 *
 * @return real tanh(x)
 */

real real_tanh(real x)
{
        // Domain check

        // Declaration of variables and structures
        real y, * z, * w, * h;

        // Mathematic algorithm
        y = x->sinh(x);
        z = x->cosh(x);
        w = z->inverse(z);
        h = y->prod(y, w);

        // Free structures
        free(y);
        free(z);
        free(w);

        // Return
        return h;
}
