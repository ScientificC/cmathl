#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cml.h>

real_t
_real_create(mfloat_t value)
{
        real_t x;

        init_real(&x);
        x.real_value = value;

        return x;
}

real_t*
_real_new(mfloat_t value)
{
        real_t* x = (real_t*) malloc(sizeof (real_t));
        (*x) = _real_create(value);

        return x;
}

real_t*
_real_clone(real_t* w)
{
        real_t* x = (real_t*) malloc(sizeof (real_t));
        (*x) = _real_create(real_value(w));

        return x;
}

void
_real_free(real_t* x)
{
        printf("%s\n", "You should free memory by using the function 'free' on the struct.");
}

mfloat_t
real_value(real_t* x)
{
        return ((mfloat_t*) x)[0];
}


void
real_set_value(real_t* x, mfloat_t w)
{
        if (sizeof(x->real_value) == sizeof(void*)) {
                x->real_value = w;
        }
}

char *
real_as_string(real_t* x)
{
        mfloat_t value = ((mfloat_t*) x)[0];

        int size = snprintf(NULL, 0, "%g", value) + 1;
        char * string = (char*) malloc(size);
        snprintf(string, size, "%g", value);

        return string;
}


void
init_real(real_t* x)
{
        (*x) = (real_t)
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
                .free = &_real_free
        };
}
