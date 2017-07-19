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
 * tan(x) function developed by using trigonometric identities
 *
 * @param real x
 *
 * @return real tan(x)
 */

real real_tan(real x)
{
        // Declaration of structures
        real y, * z, * h;

        // Mathematical algorithm
        z = x->sin(x);
        y = x->cos(x);
        h = y->isNull(y) ? real_new(NAN) : z->div(z, y);

        // Free structures
        free(y);
        free(z);

        // Return
        return h;
}
