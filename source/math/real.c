#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/math.h"

real_t
real_create(cml_t value)
{
        real_t self;

        init_real(&self);
        self.real_value = value;

        return self;
}

real
real_new(cml_t value)
{
        real self = (real) malloc(sizeof (real_t));
        (*self) = real_create(value);

        return self;
}

void
real_free(real self)
{
        printf("%s\n", "You should free memory by using the function 'free' on the struct.");
}

cml_t
real_value(real self)
{
        return self->real_value;
}


void
real_set_value(real self, cml_t x)
{
        self->real_value = x;
}

char *
real_as_string(real self)
{
        cml_t value = self->value(self);
        int size = snprintf(NULL, 0, "%g", value) + 1;
        char * string = (char*) malloc(size);
        snprintf(string, size, "%g", value);
        return string;
}


void
init_real(real self)
{
        (*self) = (real_t)
        {
                .value = &real_value,
                .setValue = &real_set_value,
                .asString = &real_as_string,
                .equals = &real_equals,
                .isNull = &real_isnull,
                .isGreater = &real_isgreater,
                .isLess = &real_isless,
                .isGreaterOrEquals = &real_isgreater_or_equals,
                .isLessOrEquals = &real_isless_or_equals,
                .isNatural = &real_isnatural,
                .isInteger = &real_isinteger,
                .isMult = &real_ismult,
                .add = &real_add,
                .prod = &real_prod,
                .sub = &real_sub,
                .div = &real_div,
                .sgn = &real_sgn,
                .abs = &real_abs,
                .divE = &real_div_e,
                .mod = &real_mod,
                .inverse = &real_inverse,
                .opposite = &real_opposite,
                .ared = &real_ared,
                .ceil = &real_ceil,
                .floor = &real_floor,
                .exp = &real_exp,
                .ln = &real_ln,
                .logB = &real_log_b,
                .pow = &real_pow,
                .root = &real_root,
                .sqrt = &real_sqrt,
                .sin = &real_sin,
                .cos = &real_cos,
                .tan = &real_tan,
                .sec = &real_sec,
                .csc = &real_csc,
                .cot = &real_cot,
                .atan = &real_atan,
                .atan2 = &real_atan2,
                .sinh = &real_sinh,
                .cosh = &real_cosh,
                .tanh = &real_tanh,
                .sech = &real_sech,
                .csch = &real_csch,
                .coth = &real_coth,
                .atanh = &real_atanh,
                .free = &real_free
        };
}
