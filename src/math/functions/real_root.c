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

/**
 * root(f, g) function developed by using the exponentiation process
 *
 * @param real x
 *
 * @return real root(f, g)
 */

real real_root(real x, real n)
{
        // Domain check
        if (n->isNatural(n)) {
                return real_new(NAN);
        }

        // Declaration of structures
        real w, * y, * z;

        // Mathematical algorithm
        w = real_new(-1.0);
        y = n->pow(n, w);
        z = x->pow(x, y);

        // Free structures
        free(w);
        free(y);

        // Return
        return z;
}
