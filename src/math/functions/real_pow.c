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

#include "../../../includes/math/cml.h"

/*
 * pow(f, g) function developed by using the exponentiation process
 * where pow(f, g) = sgn(f)e^(glog(|f|))
 *
 * @param real x
 *
 * @return real pow(f, g)
 */


real real_pow(real x, real n)
{
        // Domain check
        if (x->value(x) == 0) {
                return n->value(n) == 0 ? real(NAN) : x;
        }
        // Declaration of structures
        real s, y, z, w, k, h;
        // Mathematical algorithm
        s = x->sign(x);
        y = x->abs(x);
        z = y->ln(y);
        w = n->prod(n, z);
        k = n->exp(n);
        h = s->prod(s, k);
        // Free structures
        s->free(s);
        y->free(y);
        z->free(z);
        w->free(w);
        k->free(k);
        // Return
        return h;
}
