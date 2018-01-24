#ifndef CML_H
#error "Never use <math/include/functions/generic.h> directly; include <cml.h> instead."
#endif

#ifndef CML_MATH_GEN_FUNC_H
#define CML_MATH_GEN_FUNC_H

#ifndef _CML_MATH_FUNC
        #define _CML_MATH_FUNC(_type, _func) _type ## _ ## _func
#endif

#ifndef _CML_NO_GENERIC

        #define _CML_REAL_GENERIC_FUNC(_func, ...) \
        _Generic((_CML_ARGS_FIRST(__VA_ARGS__)), \
                 real_t: _CML_MATH_FUNC(real, _func) \
                 )(__VA_ARGS__)

        #define _CML_COMPLEX_GENERIC_FUNC(_func, ...) \
        _Generic((_CML_ARGS_FIRST(__VA_ARGS__)), \
                 complex_t*: _CML_MATH_FUNC(complex, _func) \
                 )(__VA_ARGS__)

        #define _CML_BOTH_GENERIC_FUNC(_func, ...) \
        _Generic((_CML_ARGS_FIRST(__VA_ARGS__)), \
                 complex_t*: _CML_MATH_FUNC(complex, _func), \
                 real_t: _CML_MATH_FUNC(real, _func) \
                 )(__VA_ARGS__)


        #define equals(X, Y) _CML_BOTH_GENERIC_FUNC(equals, X, Y)
        #define is_null(X) _CML_BOTH_GENERIC_FUNC(is_null, X)
        #define is_natural(X) _CML_REAL_GENERIC_FUNC(is_natural, X)
        #define is_integer(X) _CML_REAL_GENERIC_FUNC(is_integer, X)
        #define is_greater(X, Y) _CML_REAL_GENERIC_FUNC(is_greater, X, Y)
        #define is_less(X, Y) _CML_REAL_GENERIC_FUNC(is_less, X, Y)
        #define is_greater_or_equals(X, Y) _CML_REAL_GENERIC_FUNC( \
                is_greater_or_equals, \
                X, Y \
                )
        #define is_less_or_equals(X, Y) _CML_REAL_GENERIC_FUNC( \
                is_less_or_equals, \
                X, Y \
                )
        #define is_mult(X, Y) _CML_REAL_GENERIC_FUNC(is_mult, X, Y)
        #define add(X, Y) _CML_BOTH_GENERIC_FUNC(add, X, Y)
        #define prod(X, Y) _CML_BOTH_GENERIC_FUNC(prod, X, Y)
        #define sub(X, Y) _CML_BOTH_GENERIC_FUNC(sub, X, Y)
        #define div(X, Y) _CML_BOTH_GENERIC_FUNC(div, X, Y)
        #define sgn(X, Y) _CML_REAL_GENERIC_FUNC(sgn, X, Y)
        #define abs(X) _CML_REAL_GENERIC_FUNC(abs, X)
        #define floor(X) _CML_REAL_GENERIC_FUNC(floor, X)
        #define ceil(X) _CML_REAL_GENERIC_FUNC(ceil, X)
        #define div_e(X) _CML_REAL_GENERIC_FUNC(div_e, X)
        #define mod(X) _CML_REAL_GENERIC_FUNC(mod, X)
        #define inverse(X) _CML_BOTH_GENERIC_FUNC(inverse, X)
        #define opposite(X) _CML_BOTH_GENERIC_FUNC(opposite, X)
        #define ared(X) _CML_REAL_GENERIC_FUNC(ared, X)
        #define fact(X) _CML_REAL_GENERIC_FUNC(fact, X)
        #define exp(X) _CML_BOTH_GENERIC_FUNC(exp, X)
        #define ln(X) _CML_BOTH_GENERIC_FUNC(ln, X)
        #define log(X) _CML_BOTH_GENERIC_FUNC(log, X)
        #define log_b(X, Y) _CML_BOTH_GENERIC_FUNC(log_b, X, Y)
        #define pow(X, Y) _CML_REAL_GENERIC_FUNC(pow, X, Y)
        #define root(X) _CML_REAL_GENERIC_FUNC(root, X)
        #define sqrt(X) _CML_REAL_GENERIC_FUNC(sqrt, X)
        #define sin(X) _CML_BOTH_GENERIC_FUNC(sin, X)
        #define cos(X) _CML_BOTH_GENERIC_FUNC(cos, X)
        #define tan(X) _CML_BOTH_GENERIC_FUNC(tan, X)
        #define sec(X) _CML_BOTH_GENERIC_FUNC(sec, X)
        #define csc(X) _CML_BOTH_GENERIC_FUNC(csc, X)
        #define cot(X) _CML_BOTH_GENERIC_FUNC(cot, X)
        #define asin(X) _CML_BOTH_GENERIC_FUNC(asin, X)
        #define acos(X) _CML_BOTH_GENERIC_FUNC(acos, X)
        #define atan(X) _CML_BOTH_GENERIC_FUNC(atan, X)
        #define atan2(X, Y) _CML_BOTH_GENERIC_FUNC(atan2, X, Y)
        #define sinh(X) _CML_BOTH_GENERIC_FUNC(sinh, X)
        #define cosh(X) _CML_BOTH_GENERIC_FUNC(cosh, X)
        #define tanh(X) _CML_BOTH_GENERIC_FUNC(tanh, X)
        #define sech(X) _CML_BOTH_GENERIC_FUNC(sech, X)
        #define csch(X) _CML_BOTH_GENERIC_FUNC(csch, X)
        #define coth(X) _CML_BOTH_GENERIC_FUNC(coth, X)
        #define asinh(X) _CML_BOTH_GENERIC_FUNC(asinh, X)
        #define acosh(X) _CML_BOTH_GENERIC_FUNC(acosh, X)
        #define atanh(X) _CML_BOTH_GENERIC_FUNC(atanh, X)
        #define as_string(X) _CML_BOTH_GENERIC_FUNC(as_string)

#else
        #define equals(X, Y) real_equals(X, Y)
        #define is_null(X) real_is_null(X)
        #define is_natural(X) real_is_natural(X)
        #define is_integer(X) real_is_integer(X)
        #define is_greater(X, Y) real_is_integer(X, Y)
        #define is_less(X, Y) real_is_less(X, Y)
        #define is_greater_or_equals(X, Y) real_is_greater_or_equals(X, Y)
        #define is_less_or_equals(X, Y) real_is_less_or_equals(X, Y)
        #define is_mult(X, Y) real_is_mult(X, Y)
        #define add(X, Y) real_add(X, Y)
        #define prod(X, Y) real_prod(X, Y)
        #define sub(X, Y) real_sub(X, Y)
        #define div(X, Y) real_div(X, Y)
        #define sgn(X, Y) real_sgn(X, Y)
        #define abs(X) real_abs(X)
        #define floor(X) real_floor(X)
        #define ceil(X) real_ceil(X)
        #define div_e(X) real_div_e(X)
        #define mod(X) real_mod(X)
        #define inverse(X) real_inverse(X)
        #define opposite(X) real_opposite(X)
        #define ared(X) real_ared(X)
        #define fact(X) real_fact(X)
        #define exp(X) real_exp(X)
        #define ln(X) real_ln(X)
        #define log(X) real_log(X)
        #define log_b(X, Y) real_log_b(X, Y)
        #define pow(X, Y) real_pow(X, Y)
        #define root(X) real_root(X)
        #define sqrt(X) real_sqrt(X)
        #define sin(X) real_sin(X)
        #define cos(X) real_cos(X)
        #define tan(X) real_tan(X)
        #define sec(X) real_sec(X)
        #define csc(X) real_csc(X)
        #define cot(X) real_cot(X)
        #define asin(X) real_asin(X)
        #define acos(X) real_acos(X)
        #define atan(X) real_atan(X)
        #define atan2(X, Y) real_atan2(X, Y)
        #define sinh(X) real_sinh(X)
        #define cosh(X) real_cosh(X)
        #define tanh(X) real_tanh(X)
        #define sech(X) real_sech(X)
        #define csch(X) real_csch(X)
        #define coth(X) real_coth(X)
        #define asinh(X) real_asinh(X)
        #define acosh(X) real_acosh(X)
        #define atanh(X) real_atanh(X)
#endif

#define cequals(X, Y) complex_equals(X, Y)
#define cis_null(X) complex_is_null(X)
#define cis_mult(X, Y) complex_is_mult(X, Y)
#define cadd(X, Y) complex_add(X, Y)
#define cprod(X, Y) complex_prod(X, Y)
#define csub(X, Y) complex_sub(X, Y)
#define cdiv(X, Y) complex_div(X, Y)
#define cabs(X) complex_abs(X)
#define cinverse(X) complex_inverse(X)
#define cexp(X) complex_exp(X)
#define cln(X) complex_ln(X)
#define clog(X) complex_log(X)
#define clog_b(X, Y) complex_log_b(X, Y)
#define cpow(X, Y) complex_pow(X, Y)
#define croot(X) complex_root(X)
#define csqrt(X) complex_sqrt(X)
#define csin(X) complex_sin(X)
#define ccos(X) complex_cos(X)
#define ctan(X) complex_tan(X)
#define csec(X) complex_sec(X)
#define ccsc(X) complex_csc(X)
#define ccot(X) complex_cot(X)
#define casin(X) complex_asin(X)
#define cacos(X) complex_acos(X)
#define catan(X) complex_atan(X)
#define catan2(X, Y) complex_atan2(X, Y)
#define csinh(X) complex_sinh(X)
#define ccosh(X) complex_cosh(X)
#define ctanh(X) complex_tanh(X)
#define csech(X) complex_sech(X)
#define ccsch(X) complex_csch(X)
#define ccoth(X) complex_coth(X)
#define casinh(X) complex_asinh(X)
#define cacosh(X) complex_acosh(X)
#define catanh(X) complex_atanh(X)

#endif
