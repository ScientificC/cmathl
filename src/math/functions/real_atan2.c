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
 * atan2(y, x) = HALFPI*sgn(y) - atan(x/y)
 *
 */

real real_atan2(real y, real x)
{
        // Declaration of structures
        real s, h, k, j, z, w;

        // Mathematical algorithm
        s = y->sgn(y);
        h = real_new(HALFPI);
        k = x->div(x, y);
        j = k->atan(k);
        z = h->prod(h, s);
        w = z->sub(z, j);

        // Free structures
        free(s);
        free(h);
        free(k);
        free(j);
        free(z);

        // Return
        return w;
}
