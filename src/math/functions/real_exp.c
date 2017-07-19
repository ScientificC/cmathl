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
 * Development of the Taylor series of the function e^x
 *
 * @param real x: Exponent of the function
 *
 * @return real e^x
 */

real real_exp(real x)
{
        // Declaration of variables and structures
        int i;
        double ai, ex, value;

        // Mathematical algorithm
        value = x->value(x);
        ai = 1.0;
        ex = ai;
        for (i = 1; i < TOPL; ++i) {
                ai = ai*(value)/i;
                ex = ex + ai;
        }

        // Free structures

        // Return
        return real_new(ex);
}
