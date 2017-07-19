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

// An angle x is reduced to the interval [0, 2pi] by subtracting a number k of 2pi radians, where k is the integer division between x and 2pi

Real * real_ared(Real * x)
{
        // Declaration of structures
        Real * twopi, z, k, w;

        // Mathematical algorithm
        twopi = real_new(TWOPI);
        z = x->divE(x, twopi);
        k = z->prod(z, twopi);
        w = x->sub(x, k);

        // Free structures
        twopi->free(twopi);
        k->free(k);
        z->free(z);

        // Return
        return w;
}
