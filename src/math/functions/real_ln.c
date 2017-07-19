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
 * ln(x) function developed by using hyperbolic definition of Taylor Series
 * where ln(x) = arctanh((x^2 - 1)/(x^2 + 1))
 *
 * @param Real * x
 *
 * @return Real * log(x)
 */

Real * real_ln(Real * x)
{
        // Domain check
        if (x->value(x) <= 0) {
                return real_new(NAN);
        }

        // Declaration of structures
        Real * y, * z, * w, * k, * h;

        // Mathematical algorithm
        y = x->prod(x, x);
        z = real_new(y->value(y) - 1);
        w = real_new(y->value(y) + 1);
        k = z->div(z, w);
        h = k->atanh(k);

        // Free structures
        free(y);
        free(z);
        free(w);
        free(k);

        // Return
        return h;

}
