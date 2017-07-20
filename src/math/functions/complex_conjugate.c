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
 * Let z = a + bi, define the conjugate of z (w) as w = a - bi
 *
 */

complex complex_conjugate(complex self)
{
        // Declaration of structures
        complex r;
        real im;

        // Mathematic algorithm
        im = self->imaginary(self);
        r = complex_new(self->real(self), im->opposite(im));

        // Free structures
        /* free(im); don't let im be free! */

        // Return
        return r;
}
