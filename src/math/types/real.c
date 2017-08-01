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

void init_real(real);

real real_new(double value)
{
        real self = malloc(4*sizeof(double) + 50*sizeof(void *));
        init_real(self);
        self->setValue(self, value);
        return self;
}

void real_destruct(real self)
{
        printf("%s\n", "You should free memory by using the function 'free' on the struct.");
}

double real_value(real self)
{
        return self->real_value;
}


void real_set_value(real self, double x)
{
        self->real_value = x;
}

char * real_as_string(real self)
{
        double value = self->value(self);
        int size = snprintf(NULL, 0, "%g", value) + 1;
        char * string = (char*) malloc(size);
        snprintf(string, size, "%g", value);
        return string;
}


void init_real(real self)
{
        self->value = &real_value;
        self->setValue = &real_set_value;
        self->asString = &real_as_string;
        self->equals = &real_equals;
        self->isNull = &real_isnull;
        self->isGreater = &real_isgreater;
        self->isLess = &real_isless;
        self->isGreaterOrEquals = &real_isgreater_or_equals;
        self->isLessOrEquals = &real_isless_or_equals;
        self->isNatural = &real_isnatural;
        self->isInteger = &real_isinteger;
        self->isMult = &real_ismult;
        self->add = &real_add;
        self->prod = &real_prod;
        self->sub = &real_sub;
        self->div = &real_div;
        self->sgn = &real_sgn;
        self->abs = &real_abs;
        self->divE = &real_div_e;
        self->mod = &real_mod;
        self->inverse = &real_inverse;
        self->opposite = &real_opposite;
        self->ared = &real_ared;
        self->ceil = &real_ceil;
        self->floor = &real_floor;
        self->exp = &real_exp;
        self->ln = &real_ln;
        self->logB = &real_log_b;
        self->pow = &real_pow;
        self->root = &real_root;
        self->sqrt = &real_sqrt;
        self->sin = &real_sin;
        self->cos = &real_cos;
        self->tan = &real_tan;
        self->sec = &real_sec;
        self->csc = &real_csc;
        self->cot = &real_cot;
        self->sinh = &real_sinh;
        self->cosh = &real_cosh;
        self->tanh = &real_tanh;
        self->sech = &real_sech;
        self->csch = &real_csch;
        self->coth = &real_coth;
        self->atanh = &real_atanh;
}
