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

Real * real_new(double value)
{
        Real * self = malloc(4*sizeof(double) + 50*sizeof(void *));
        __real_init__(self);
        self->setValue(self, value);
        return self;
}

void real_destruct(Real * self)
{
        free(self);
}

double real_value(Real * self)
{
        return self->real_value;
}


void real_set_value(Real * self, double x)
{
        self->real_value = x;
}

char * real_as_string(Real * self)
{
        return "a";
}


void __real_init__(Real * self)
{
        self->value = &real_value;
        self->setValue = &real_set_value;
        self->asString = &real_as_string;
        self->sgn = &real_sgn;
        self->abs = &real_abs;
        self->add = &real_add;
        self->prod = &real_prod;
        self->sub = &real_sub;
        self->div = &real_div;
        self->divE = &real_div_e;
        self->mod = &real_mod;
        self->ared = &real_ared;
        self->fact = &real_fact;
        self->ceil = &real_ceil;
        self->floor = &real_floor;
        self->exp = &real_exp;
        self->ln = &real_ln;
        self->logB = &real_log_b;
        self->log = &real_log;
        self->pow = &real_pow;
        self->root = &real_root;
        self->sqrt = &real_sqrt;
        self->sin = &real_sin;
        self->cos = &real_cos;
        self->tan = &real_tan;
        self->sec = &real_sec;
        self->csc = &real_csc;
        self->cot = &real_cot;
}
