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

double __sin__(double x)
{
        double ai, p;
        int i;

        ai = x;
        p = ai;

        for (i = 1; i <= TOPL; ++i) {
                ai = -ai*(x)*(x)/(2*i*(2*i+1));
                p = p + ai;
        }

        return p;
}

real real_sin(real x)
{
        // Domain check
        real c = real_new(PI);
        if (x->isMult(x, c)) {
                return real_new(0.0);
        }

        // Declaration of variables and structures
        real s, * y, * z, * w, * h;
        double r;


        // Mathematical algorithm
        s = x->sgn(x);
        y = x->abs(x);
        z = y->ared(y);

        r = __sin__(z->value(z));

        w = real_new(r);
        h = w->prod(w, s);

        // Free structures
        free(s);
        free(y);
        free(z);
        free(w);
        free(c);

        // Return
        return h;
}
