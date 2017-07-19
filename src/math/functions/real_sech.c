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
 * "sech(x)" function developed by using Euler relationships
 *
 * @param real x
 *
 * @return real sech(x)
 */

real real_sech(real x)
{
        // Domain check

        // Declaration of variables and structures
        real y, * h;

        // Mathematic algorithm
        y = x->cosh(x);
        h = y->inverse(y);

        // Free structures
        free(y);

        // Return
        return h;
}
