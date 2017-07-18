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

complex complex(real real_part, real imaginary_part)
{
        complex self = malloc(4*sizeof(double) + 45*sizeof(void *));
        self->real = &complex_get_real;
        self->imaginary = &complex_get_imaginary;
        self->setReal = &complex_set_real;
        self->setImaginary = &complex_set_imaginary;
        self->parts = &complex_get_parts;
        self->asString = &complex_as_string;
        self->setReal(self, real_part);
        self->setImaginary(self, imaginary_part);
        return self;
}

void complex_destruct(complex self)
{
        free(z);
}

real complex_get_real(complex self)
{
        return self->real_part;
}

real complex_get_imaginary(complex self)
{
        return self->imaginary_part;
}

void complex_set_real(complex self, real x)
{
        self->real_part = x;
}

void complex_set_imaginary(complex self, real x)
{
        self->imaginary_part = x;
}

real * complex_get_parts(complex self)
{
        real * parts = malloc(sizeof(*parts));
        parts[0] = self->real(self);
        parts[1] = self->imaginary(self);
        return parts;
}

char * complex_as_string(complex self)
{
        return "a + bi";
}
