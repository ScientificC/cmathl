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
 * cos(x) function developed by using Taylor Series
 *
 * @param Real * x
 *
 * @return Real * cos(x)
 */

Real * real_cos(Real * x)
{
        // Declaration of structures
        Real * half_pi, * y, * z, * h;

        // Mathematical algorithm
        half_pi = real_new(HALFPI);
        y = x->abs(x);
        z = y->add(y, half_pi);
        h = z->sin(z);

        // Free structures
        half_pi->free(half_pi);
        y->free(y);
        z->free(z);

        // Return
        return h;
}
