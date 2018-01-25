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
         default: _CML_MATH_FUNC(real, _func), \
                 real_t: _CML_MATH_FUNC(real, _func) \
                 )(__VA_ARGS__)

        #define _CML_COMPLEX_GENERIC_FUNC(_func, ...) \
        _Generic((_CML_ARGS_FIRST(__VA_ARGS__)), \
                 complex_t: _CML_MATH_FUNC(complex, _func) \
                 )(__VA_ARGS__)

        #define _CML_BOTH_GENERIC_FUNC(_func, ...) \
        _Generic((_CML_ARGS_FIRST(__VA_ARGS__)), \
         default: _CML_MATH_FUNC(real, _func), \
                 complex_t: _CML_MATH_FUNC(complex, _func), \
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
        #error "<math/include/functions/generic.h> not implemented for this compiler"
#endif
#endif
