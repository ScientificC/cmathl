#ifndef CML_H
#error "Never use <math/functions.h> directly; include <cml.h> instead."
#endif

#ifndef CML_MATH_GEN_FUNC_H
#define CML_MATH_GEN_FUNC_H

#ifndef _CML_NO_GENERIC
        #define _CML_MATH_FUNC(_type, _func) _type ## _ ## _func

        #define _CML_REAL_GENERIC_FUNC_1(X, _func) _Generic((X), \
                                                            real_t*: _CML_MATH_FUNC(real, _func) \
                                                            )(X)

        #define _CML_COMPLEX_GENERIC_FUNC_1(X, _func) _Generic((X), \
                                                               complex_t*: _CML_MATH_FUNC(complex, _func) \
                                                               )(X)

        #define _CML_REAL_GENERIC_FUNC_2(X, Y, _func) _Generic((X), \
                                                               real_t*: _Generic((Y), \
                                                                         default: _CML_MATH_FUNC(real, _func), \
                                                                                 real_t*: _CML_MATH_FUNC(real, _func) \
                                                                                 ) \
                                                               )(X, Y)

        #define _CML_COMPLEX_GENERIC_FUNC_2(X, Y, _func) _Generic((X), \
                                                                  complex_t*: _Generic((Y), \
                                                                               default: _CML_MATH_FUNC(complex, _func), \
                                                                                       complex_t*: _CML_MATH_FUNC(complex, _func) \
                                                                                       ) \
                                                                  )(X, Y)

        #define _CML_BOTH_GENERIC_FUNC_1(X, _func) _Generic((X), \
                                                            complex_t*: _CML_MATH_FUNC(complex, _func), \
                                                            real_t*: _CML_MATH_FUNC(real, _func) \
                                                            )(X)

        #define _CML_BOTH_GENERIC_FUNC_2(X, Y, _func) _Generic((X), \
                                                               complex_t*: _Generic((Y), \
                                                                            default: _CML_MATH_FUNC(complex, _func), \
                                                                                    complex_t*: _CML_MATH_FUNC(complex, _func) \
                                                                                    ), \
                                                               real_t*: _Generic((Y), \
                                                                         default: _CML_MATH_FUNC(real, _func), \
                                                                                 real_t*: _CML_MATH_FUNC(real, _func) \
                                                                                 ) \
                                                               )(X, Y)

        #define equals(X, Y) _CML_BOTH_GENERIC_FUNC_2(X, Y, equals)
        #define isnull(X) _CML_BOTH_GENERIC_FUNC_1(X, isnull)
        #define isnatural(X) _CML_REAL_GENERIC_FUNC_1(X, isnatural)
        #define isinteger(X) _CML_REAL_GENERIC_FUNC_1(X, isinteger)
        #define isgreater(X, Y) _CML_REAL_GENERIC_FUNC_2(X, Y, isgreater)
        #define isless(X, Y) _CML_REAL_GENERIC_FUNC_2(X, Y, isless)
        #define isgreater_or_equals(X, Y) _CML_REAL_GENERIC_FUNC_2( \
                X, Y, \
                isgreater_or_equals \
                )
        #define isless_or_equals(X, Y) _CML_REAL_GENERIC_FUNC_2( \
                X, Y, \
                isless_or_equals \
                )
        #define ismult(X, Y) _CML_REAL_GENERIC_FUNC_2( \
                X, Y, \
                ismult \
                )
        #define add(X, Y) _CML_BOTH_GENERIC_FUNC_2(X, Y, add)
        #define prod(X, Y) _CML_BOTH_GENERIC_FUNC_2(X, Y, prod)
        #define sub(X, Y) _CML_BOTH_GENERIC_FUNC_2(X, Y, sub)
        #define div(X, Y) _CML_BOTH_GENERIC_FUNC_2(X, Y, div)
        #define sgn(X, Y) _CML_REAL_GENERIC_FUNC_1(X, Y, sgn)
        #define abs(X) _CML_REAL_GENERIC_FUNC_1(X, abs)
        #define floor(X) _CML_REAL_GENERIC_FUNC_1(X, floor)
        #define ceil(X) _CML_REAL_GENERIC_FUNC_1(X, ceil)
        #define div_e(X) _CML_REAL_GENERIC_FUNC_1(X, div_e)
        #define mod(X) _CML_REAL_GENERIC_FUNC_1(X, mod)
        #define inverse(X) _CML_BOTH_GENERIC_FUNC_1(X, inverse)
        #define opposite(X) _CML_BOTH_GENERIC_FUNC_1(X, opposite)
        #define ared(X) _CML_REAL_GENERIC_FUNC_1(X, ared)
        #define fact(X) _CML_REAL_GENERIC_FUNC_1(X, fact)
        #define exp(X) _CML_BOTH_GENERIC_FUNC_1(X, exp)
        #define ln(X) _CML_BOTH_GENERIC_FUNC_1(X, ln)
        #define log(X) _CML_BOTH_GENERIC_FUNC_1(X, log)
        #define log_b(X, Y) _CML_BOTH_GENERIC_FUNC_2(X, Y, log_b)
        #define pow(X, Y) _CML_REAL_GENERIC_FUNC_2(X, Y, pow)
        #define root(X) _CML_REAL_GENERIC_FUNC_1(X, root)
        #define sqrt(X) _CML_REAL_GENERIC_FUNC_1(X, sqrt)
        #define sin(X) _CML_BOTH_GENERIC_FUNC_1(X, sin)
        #define cos(X) _CML_BOTH_GENERIC_FUNC_1(X, cos)
        #define tan(X) _CML_BOTH_GENERIC_FUNC_1(X, tan)
        #define sec(X) _CML_BOTH_GENERIC_FUNC_1(X, sec)
        #define csc(X) _CML_BOTH_GENERIC_FUNC_1(X, csc)
        #define cot(X) _CML_BOTH_GENERIC_FUNC_1(X, cot)
        #define asin(X) _CML_BOTH_GENERIC_FUNC_1(X, asin)
        #define acos(X) _CML_BOTH_GENERIC_FUNC_1(X, acos)
        #define atan(X) _CML_BOTH_GENERIC_FUNC_1(X, atan)
        #define atan2(X, Y) _CML_BOTH_GENERIC_FUNC_1(X, Y, atan2)
        #define sinh(X) _CML_BOTH_GENERIC_FUNC_1(X, sinh)
        #define cosh(X) _CML_BOTH_GENERIC_FUNC_1(X, cosh)
        #define tanh(X) _CML_BOTH_GENERIC_FUNC_1(X, tanh)
        #define sech(X) _CML_BOTH_GENERIC_FUNC_1(X, sech)
        #define csch(X) _CML_BOTH_GENERIC_FUNC_1(X, csch)
        #define coth(X) _CML_BOTH_GENERIC_FUNC_1(X, coth)
        #define asinh(X) _CML_BOTH_GENERIC_FUNC_1(X, asinh)
        #define acosh(X) _CML_BOTH_GENERIC_FUNC_1(X, acosh)
        #define atanh(X) _CML_BOTH_GENERIC_FUNC_1(X, atanh)
        #define as_string(X) _CML_BOTH_GENERIC_FUNC_1(X, as_string)
#elif !defined _CML_NO_BUILTIN_TYPES
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
