#ifndef CML_H
#error "Never use <math/functions.h> directly; include <cml.h> instead."
#endif

#ifndef CML_MATH_GEN_FUNC_H
#define CML_MATH_GEN_FUNC_H

#ifndef _CML_NO_GENERIC
        #define add(X, Y) _Generic((X), \
                                   complex_t*: _Generic((Y), \
                                                default: complex_add, \
                                                        complex_t*: complex_add \
                                                        ), \
                                   real_t*: _Generic((Y), \
                                             default: real_add, \
                                                     real_t*: real_add \
                                                     ) \
                                   )(X, Y)

        #define prod(X, Y) _Generic((X), \
                                    complex_t*: _Generic((Y), \
                                                 default: complex_prod, \
                                                         complex_t*: complex_prod \
                                                         ), \
                                    real_t*: _Generic((Y), \
                                              default: real_prod, \
                                                      real_t*: real_prod \
                                                      ) \
                                    )(X, Y)

        #define sub(X, Y) _Generic((X), \
                                   complex_t*: _Generic((Y), \
                                                default: complex_sub, \
                                                        complex_t*: complex_sub \
                                                        ), \
                                   real_t*: _Generic((Y), \
                                             default: real_sub, \
                                                     real_t*: real_sub \
                                                     ) \
                                   )(X, Y)

        #define div(X, Y) _Generic((X), \
                                   complex_t*: _Generic((Y), \
                                                default: complex_div, \
                                                        complex_t*: complex_div \
                                                        ), \
                                   real_t*: _Generic((Y), \
                                             default: real_div, \
                                                     real_t*: real_div \
                                                     ) \
                                   )(X, Y)

        #define inverse(X) _Generic((X), \
                                    complex_t*: complex_inverse, \
                                    real_t*: real_inverse \
                                    )(X)

        #define opposite(X) _Generic((X), \
                                     real_t*: real_opposite \
                                     )(X)

        #define exp(X) _Generic((X), \
                                complex_t*: complex_exp, \
                                real_t*: real_exp \
                                )(X)

        #define log(X) _Generic((X), \
                                complex_t*: complex_log, \
                                real_t*: real_ln \
                                )(X)

        #define ln(X) log(X)

        #define log_b(X, Y) _Generic((X), \
                                     complex_t*: _Generic((Y), \
                                                  default: complex_log_b, \
                                                          complex_t*: complex_log_b \
                                                          ), \
                                     real_t*: _Generic((Y), \
                                               default: real_log_b, \
                                                       real_t*: real_log_b \
                                                       ) \
                                     )(X, Y)

        #define pow(X, Y) _Generic((X), \
                                   real_t*: _Generic((Y), \
                                             default: real_pow, \
                                                     real_t*: real_pow \
                                                     ) \
                                   )(X, Y)

        #define root(X) _Generic((X), \
                                 real_t*: real_root \
                                 )(X)

        #define sqrt(X) _Generic((X), \
                                 real_t*: real_sqrt \
                                 )(X)

        #define sin(X) _Generic((X), \
                                complex_t*: complex_sin, \
                                real_t*: real_sin \
                                )(X)

        #define cos(X) _Generic((X), \
                                complex_t*: complex_cos, \
                                real_t*: real_cos \
                                )(X)

        #define tan(X) _Generic((X), \
                                complex_t*: complex_tan, \
                                real_t*: real_tan \
                                )(X)

        #define sec(X) _Generic((X), \
                                complex_t*: complex_sec, \
                                real_t*: real_sec \
                                )(X)

        #define csc(X) _Generic((X), \
                                complex_t*: complex_csc, \
                                real_t*: real_csc \
                                )(X)

        #define cot(X) _Generic((X), \
                                complex_t*: complex_cot, \
                                real_t*: real_cot \
                                )(X)

        #define asin(X) _Generic((X), \
                                 real_t*: real_asin \
                                 )(X)

        #define acos(X) _Generic((X), \
                                 real_t*: real_acos \
                                 )(X)

        #define atan(X) _Generic((X), \
                                 real_t*: real_atan \
                                 )(X)

        #define atan2(X, Y) _Generic((X), \
                                     real_t*: _Generic((Y), \
                                               default: real_atan2, \
                                                       real_t*: real_atan2 \
                                                       ) \
                                     )(X, Y)

        #define sinh(X) _Generic((X), \
                                 complex_t*: complex_sinh, \
                                 real_t*: real_sinh \
                                 )(X)

        #define cosh(X) _Generic((X), \
                                 complex_t*: complex_cosh, \
                                 real_t*: real_cosh \
                                 )(X)

        #define tanh(X) _Generic((X), \
                                 complex_t*: complex_tanh, \
                                 real_t*: real_tanh \
                                 )(X)

        #define asinh(X) _Generic((X), \
                                  real_t*: real_asinh \
                                  )(X)

        #define acosh(X) _Generic((X), \
                                  real_t*: real_acosh \
                                  )(X)

        #define atanh(X) _Generic((X), \
                                  real_t*: real_atanh \
                                  )(X)

        #define as_string(X) _Generic((X), \
                                      complex_t*: complex_as_string, \
                                      real_t*: real_as_string \
                                      )(X)
#else
#ifdef _CML_NO_BUILTIN_TYPES
        #define equals(X, Y) (X)->equals(X, Y)
        #define isnull(X) (X)->isNull(X, Y)
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
#else

        #define _CML_FUNC(_type, _func) {_type ## _ ## _func}

        #define equals(X, Y) ({ \
                typeof(X)_tmp; \
                if (_CML_B_T_C_P(typeof(X), real) \
                    || _CML_B_T_C_P(typeof(X), complex)) { \
                        _tmp = _CML_FUNC(typeof(X), equals)(X, Y); \
                } \
                tmp; \
        })

        #define isnull(X) ({ \
                typeof(X)_tmp; \
                if (_CML_B_T_C_P(typeof(X), real) \
                    || _CML_B_T_C_P(typeof(X), complex)) { \
                        _tmp = _CML_FUNC(typeof(X), isnull)(X); \
                } \
                tmp; \
        })

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
#endif
