#ifndef CML_H
#error "Never use <math/functions.h> directly; include <cml.h> instead."
#endif

#ifndef CML_MATH_GEN_FUNC_H
#define CML_MATH_GEN_FUNC_H

#ifndef _CML_MATH_FUNC
        #define _CML_MATH_FUNC(_type, _func) _type ## _ ## _func
#endif

#ifndef _CML_NO_GENERIC

        #define _CML_REAL_GENERIC_FUNC(_func, ...) \
        _Generic((_CML_ARGS_FIRST(__VA_ARGS__)), \
                 real_t*: _CML_MATH_FUNC(real, _func) \
                 )(__VA_ARGS__)

        #define _CML_COMPLEX_GENERIC_FUNC(_func, ...) \
        _Generic((_CML_ARGS_FIRST(__VA_ARGS__)), \
                 complex_t*: _CML_MATH_FUNC(complex, _func) \
                 )(__VA_ARGS__)

        #define _CML_BOTH_GENERIC_FUNC(_func, ...) \
        _Generic((_CML_ARGS_FIRST(__VA_ARGS__)), \
                 complex_t*: _CML_MATH_FUNC(complex, _func), \
                 real_t*: _CML_MATH_FUNC(real, _func) \
                 )(__VA_ARGS__)

#elif !defined _CML_NO_EXTENSIONS
        #define _CML_REAL_GENERIC_FUNC(_func, ...) real_ ## _func(__VA_ARGS__)

        #define _CML_COMPLEX_GENERIC_FUNC(_func, ...) complex_ ## _func(__VA_ARGS__)

        #define _CML_BOTH_GENERIC_FUNC(_func, ...) ({ \
                if (_CML_B_T_C_P(__typeof(_CML_ARGS_FIRST(__VA_ARGS__)), real) \
                    || _CML_B_T_C_P(__typeof(_CML_ARGS_FIRST(__VA_ARGS__)), real_t*)) { \
                        real_ ## _func(__VA_ARGS__); \
                } else if (_CML_B_T_C_P(__typeof(_CML_ARGS_FIRST(__VA_ARGS__)), complex) \
                           || _CML_B_T_C_P(__typeof(_CML_ARGS_FIRST(__VA_ARGS__)), complex_t*)) { \
                        complex_ ## _func(__VA_ARGS__); \
                } \
        })
#endif

#if !(defined _CML_NO_GENERIC && defined _CML_NO_EXTENSIONS)
        #define equals(X, Y) _CML_BOTH_GENERIC_FUNC(equals, X, Y)
        #define isnull(X) _CML_BOTH_GENERIC_FUNC(isnull, X)
        #define isnatural(X) _CML_REAL_GENERIC_FUNC(isnatural, X)
        #define isinteger(X) _CML_REAL_GENERIC_FUNC(isinteger, X)
        #define isgreater(X, Y) _CML_REAL_GENERIC_FUNC(isgreater, X, Y)
        #define isless(X, Y) _CML_REAL_GENERIC_FUNC(isless, X, Y)
        #define isgreater_or_equals(X, Y) _CML_REAL_GENERIC_FUNC( \
                isgreater_or_equals, \
                X, Y \
                )
        #define isless_or_equals(X, Y) _CML_REAL_GENERIC_FUNC( \
                isless_or_equals, \
                X, Y \
                )
        #define ismult(X, Y) _CML_REAL_GENERIC_FUNC(ismult, X, Y)
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
        #define equals(X, Y) (X)->equals(X, Y)
        #define isnull(X) (X)->isNull(X)
        #define isnatural(X) (X)->isNatural(X)
        #define isinteger(X) (X)->isInteger(X)
        #define isgreater(X, Y) (X)->isGreater(X, Y)
        #define isless(X, Y) (X)->isLess(X, Y)
        #define isgreater_or_equals(X, Y) (X)->isGreaterOrEquals(X, Y)
        #define isless_or_equals(X, Y) (X)->isLessOrEquals(X, Y)
        #define ismult(X, Y) (X)->isMult(X, Y)
        #define add(X, Y) (X)->add(X, Y)
        #define prod(X, Y) (X)->prod(X, Y)
        #define sub(X, Y) (X)->sub(X, Y)
        #define div(X, Y) (X)->div(X, Y)
        #define sgn(X) (X)->sgn(X)
        #define abs(X) (X)->abs(X)
        #define floor(X) (X)->floor(X)
        #define ceil(X) (X)->ceil(X)
        #define div_e(X, Y) (X)->div_e(X, Y)
        #define mod(X, Y) (X)->mod(X, Y)
        #define inverse(X) (X)->inverse(X)
        #define opposite(X) (X)->opposite(X)
        #define ared(X) (X)->ared(X)
        #define fact(X) (X)->fact(X)
        #define exp(X) (X)->exp(X)
        #define ln(X) (X)->ln(X)
        #define log(X) (X)->log(X)
        #define log_b(X, Y) (X)->logB(X)
        #define pow(X, Y) (X)->pow(X, Y)
        #define root(X, Y) (X)->root(X, Y)
        #define sqrt(X) (X)->sqrt(X)
        #define sin(X) (X)->sin(X)
        #define cos(X) (X)->cos(X)
        #define tan(X) (X)->tan(X)
        #define sec(X) (X)->sec(X)
        #define csc(X) (X)->csc(X)
        #define cot(X) (X)->cot(X)
        #define asin(X) (X)->asin(X)
        #define acos(X) (X)->acos(X)
        #define atan(X) (X)->atan(X)
        #define atan2(X, Y) (X)->atan2(X, Y)
        #define sinh(X) (X)->sinh(X)
        #define cosh(X) (X)->cosh(X)
        #define tanh(X) (X)->tanh(X)
        #define sech(X) (X)->sech(X)
        #define csch(X) (X)->csch(X)
        #define coth(X) (X)->coth(X)
        #define asinh(X) (X)->asinh(X)
        #define acosh(X) (X)->acosh(X)
        #define atanh(X) (X)->atanh(X)
        #define as_string(X) (X)->asString(X)
#endif


#endif
