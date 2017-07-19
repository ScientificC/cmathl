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
 * sin(x) function developed by using Taylor Series
 *
 * @param real x
 *
 * @return real sin(x)
 */

real real_sin(real x)
{
        // Domain check
        if (ismult(x->value(x), PI)) {
                return real(0.0);
        }

        // Declaration of variables and structures
        double y;

        // Mathematical algorithm
        y = sin((double) x->value(x));

        // Free structures

        // Return
        return real(y);
}

/* real real_sin(real x)
   {
   // Domain check
   if (ismult(x->value(x), PI)) {
   return real(0.0);
   }
   // Declaration of variables and structures
   real s, y, z, w, h;
   double ai, p;
   // Mathematical algorithm
   s = x->sgn(x);
   y = x->abs(x);
   z = y->ared(y);
   ai = z->value(z);
   p = ai;
   int i;
   for (i = 1; i <= TOPL; ++i) {
   ai = -ai*(z->value(z))*(z->value(z))/(2*i*(2*i+1));
   p = p + ai;
   }
   w = real(p);
   h = w->prod(w, s);
   // Free structures
   s->free(s);
   y->free(y);
   z->free(z);
   w->free(w);
   // Return
   return h;
   } */
