#ifndef CML_MATH_GEN_FUNC_H
#define CML_MATH_GEN_FUNC_H

#define CML_H
#include <cml/_common/default.h>
#include <cml/_common/inline.h>
#include <cml/_common/machine.h>

#include <cml/complex.h>
#include <cml/math.h>

#ifndef __CML_MATH_FUNC
        #define __CML_MATH_FUNC(_type, _func) cml_ ## _type ## _ ## _func
#endif

#ifndef __CML_NO_GENERIC

        #define __CML_REAL_GENERIC_FUNC(_func, ...) \
        _Generic((__CML_ARGS_FIRST(__VA_ARGS__)), \
         default: __CML_MATH_FUNC(real, _func), \
                 double : __CML_MATH_FUNC(real, _func) \
                 )(__VA_ARGS__)

        #define __CML_COMPLEX_GENERIC_FUNC(_func, ...) \
        _Generic((__CML_ARGS_FIRST(__VA_ARGS__)), \
                 cml_complex_t: __CML_MATH_FUNC(complex, _func) \
                 )(__VA_ARGS__)

        #define __CML_BOTH_GENERIC_FUNC(_func, ...) \
        _Generic((__CML_ARGS_FIRST(__VA_ARGS__)), \
         default: __CML_MATH_FUNC(real, _func), \
                 cml_complex_t: __CML_MATH_FUNC(complex, _func), \
                 double : __CML_MATH_FUNC(real, _func) \
                 )(__VA_ARGS__)

        #define equal(X, Y) __CML_BOTH_GENERIC_FUNC(equal, X, Y)
        #define isnull(X) __CML_BOTH_GENERIC_FUNC(isnull, X)
        #define isnatural(X) __CML_REAL_GENERIC_FUNC(isnatural, X)
        #define isinteger(X) __CML_REAL_GENERIC_FUNC(isinteger, X)
        #define isgreater(X, Y) __CML_REAL_GENERIC_FUNC(isgreater, X, Y)
        #define isless(X, Y) __CML_REAL_GENERIC_FUNC(isless, X, Y)
        #define isgreaterequal(X, Y) __CML_REAL_GENERIC_FUNC( \
                isgreaterequal, \
                X, Y \
                )
        #define islessequal(X, Y) __CML_REAL_GENERIC_FUNC( \
                islessequal, \
                X, Y \
                )
        #define ismult(X, Y) __CML_REAL_GENERIC_FUNC(ismult, X, Y)
        #define add(X, Y) __CML_BOTH_GENERIC_FUNC(add, X, Y)
        #define prod(X, Y) __CML_BOTH_GENERIC_FUNC(prod, X, Y)
        #define sub(X, Y) __CML_BOTH_GENERIC_FUNC(sub, X, Y)
        #define div(X, Y) __CML_BOTH_GENERIC_FUNC(div, X, Y)
        #define sgn(X, Y) __CML_REAL_GENERIC_FUNC(sgn, X, Y)
        #define abs(X) __CML_REAL_GENERIC_FUNC(abs, X)
        #define floor(X) __CML_REAL_GENERIC_FUNC(floor, X)
        #define ceil(X) __CML_REAL_GENERIC_FUNC(ceil, X)
        #define div_e(X) __CML_REAL_GENERIC_FUNC(div_e, X)
        #define mod(X) __CML_REAL_GENERIC_FUNC(mod, X)
        #define inverse(X) __CML_BOTH_GENERIC_FUNC(inverse, X)
        #define opposite(X) __CML_BOTH_GENERIC_FUNC(opposite, X)
        #define ared(X) __CML_REAL_GENERIC_FUNC(ared, X)
        #define fact(X) __CML_REAL_GENERIC_FUNC(fact, X)
        #define exp(X) __CML_BOTH_GENERIC_FUNC(exp, X)
        #define ln(X) __CML_BOTH_GENERIC_FUNC(ln, X)
        #define log(X) __CML_BOTH_GENERIC_FUNC(log, X)
        #define log_b(X, Y) __CML_BOTH_GENERIC_FUNC(log_b, X, Y)
        #define pow(X, Y) __CML_REAL_GENERIC_FUNC(pow, X, Y)
        #define root(X) __CML_REAL_GENERIC_FUNC(root, X)
        #define sqrt(X) __CML_REAL_GENERIC_FUNC(sqrt, X)
        #define sin(X) __CML_BOTH_GENERIC_FUNC(sin, X)
        #define cos(X) __CML_BOTH_GENERIC_FUNC(cos, X)
        #define tan(X) __CML_BOTH_GENERIC_FUNC(tan, X)
        #define sec(X) __CML_BOTH_GENERIC_FUNC(sec, X)
        #define csc(X) __CML_BOTH_GENERIC_FUNC(csc, X)
        #define cot(X) __CML_BOTH_GENERIC_FUNC(cot, X)
        #define asin(X) __CML_BOTH_GENERIC_FUNC(asin, X)
        #define acos(X) __CML_BOTH_GENERIC_FUNC(acos, X)
        #define atan(X) __CML_BOTH_GENERIC_FUNC(atan, X)
        #define atan2(X, Y) __CML_BOTH_GENERIC_FUNC(atan2, X, Y)
        #define sinh(X) __CML_BOTH_GENERIC_FUNC(sinh, X)
        #define cosh(X) __CML_BOTH_GENERIC_FUNC(cosh, X)
        #define tanh(X) __CML_BOTH_GENERIC_FUNC(tanh, X)
        #define sech(X) __CML_BOTH_GENERIC_FUNC(sech, X)
        #define csch(X) __CML_BOTH_GENERIC_FUNC(csch, X)
        #define coth(X) __CML_BOTH_GENERIC_FUNC(coth, X)
        #define asinh(X) __CML_BOTH_GENERIC_FUNC(asinh, X)
        #define acosh(X) __CML_BOTH_GENERIC_FUNC(acosh, X)
        #define atanh(X) __CML_BOTH_GENERIC_FUNC(atanh, X)
        #define as_string(X) __CML_BOTH_GENERIC_FUNC(as_string)
#else
        #error "<cml/tgmath.h> not implemented for this compiler"
#endif
#endif
