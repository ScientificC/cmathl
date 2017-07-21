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

complex complex_new(real real_part, real imaginary_part)
{
        complex self = malloc(4*sizeof(double) + 45*sizeof(void *));
        __complex_init__(self);
        self->setReal(self, real_part);
        self->setImaginary(self, imaginary_part);
        return self;
}

void complex_destruct(complex self)
{
        printf("%s\n", "You should free memory by using the function 'free' on the struct.");
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

real* complex_get_parts(complex self)
{
        real* parts = malloc(sizeof(*parts));
        parts[0] = self->real(self);
        parts[1] = self->imaginary(self);
        return parts;
}

char * complex_as_string(complex self)
{
        return "a + bi";
}

void __complex_init__(complex self) {
        self->real = &complex_get_real;
        self->imaginary = &complex_get_imaginary;
        self->setReal = &complex_set_real;
        self->setImaginary = &complex_set_imaginary;
        self->parts = &complex_get_parts;
        self->asString = &complex_as_string;
        self->add = &complex_add;
        self->prod = &complex_prod;
        self->sub = &complex_sub;
        self->div = &complex_div;
        self->abs = &complex_abs;
        self->inverse = &complex_inverse;
        self->conjugate = &complex_conjugate;
        self->exp = &complex_exp;
        self->sin = &complex_sin;
        self->cos = &complex_cos;
        self->tan = &complex_tan;
}
