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
 * The logarithm logb(x) can be computed from the logarithms of x and b with respect to an arbitrary base k using the following formula:
 * log_b{x} = log_k{x} / log_k(b)
 *
 * @param real x
 *
 * @return real log_b(x)
 */

real real_log_b(real x, real b)
{
        // Declaration of structures
        real y, z, w;

        // Mathematical algorithm
        y = x->ln(x);
        z = b->ln(b);
        w = y->div(y, z);

        // Free structures
        free(y);
        free(z);

        // Return
        return w;

}
