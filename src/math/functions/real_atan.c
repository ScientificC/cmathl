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

double __atan__(double x)
{
        int i;
        double ai_n = x,
               p = ai_n;

        for (i = 1; i <= TOPL; i += 2) {
                ai_n = -ai_n*x*x;
                p += ai_n/((double) i + 2.0);
        }

        return p;
}


real real_atan(real x)
{
        // Domain check
        real a, u;
        a = x->abs(x);
        u = real_new(1.0);
        /*
        if (a->isGreaterOrEquals(a, u)) {
              free(a);
              free(u);
              return real_new(NAN);
        }
        */


        // Declaration of structures
        double y;
        real s, h, w;

        // Mathematical algorithm
        s = x->sgn(x);
        y = __atan__(a->value(a));
        h = real_new(y);
        w = s->prod(s, h);

        // Free structures
        free(a);
        free(u);
        free(s);
        free(h);

        // Return
        return w;
}
