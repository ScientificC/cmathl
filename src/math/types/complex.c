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

Complex * complex_new(Real * real_part, Real * imaginary_part)
{
        Complex * self = malloc(4*sizeof(double) + 45*sizeof(void *));
        __complex_init__(self);
        self->setReal(self, real_part);
        self->setImaginary(self, imaginary_part);
        return self;
}

void complex_destruct(Complex * self)
{
        free(self);
}

Real * complex_get_real(Complex * self)
{
        return self->real_part;
}

Real * complex_get_imaginary(Complex * self)
{
        return self->imaginary_part;
}

void complex_set_real(Complex * self, Real * x)
{
        self->real_part = x;
}

void complex_set_imaginary(Complex * self, Real * x)
{
        self->imaginary_part = x;
}

Real ** complex_get_parts(Complex * self)
{
        Real ** parts = malloc(sizeof(*parts));
        parts[0] = self->getReal(self);
        parts[1] = self->getImaginary(self);
        return parts;
}

char * complex_as_string(Complex * self)
{
        return "a + bi";
}

void __complex_init__(Complex * self) {
        self->getReal = &complex_get_real;
        self->getImaginary = &complex_get_imaginary;
        self->setReal = &complex_set_real;
        self->setImaginary = &complex_set_imaginary;
        self->parts = &complex_get_parts;
        self->asString = &complex_as_string;
}
