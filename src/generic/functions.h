#ifndef CML_H
#error "Never use <generic/functions.h> directly; include <cml.h> instead."
#endif

#ifndef CML_GEN_FUN_H
#define CML_GEN_FUNC_H

#ifndef CML_NO_GENERIC
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
#else
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
        #define atan(X) (X)->atan(X)
        #define atan2(X, Y) (X)->atan2(X, Y)
        #define sinh(X) (X)->sinh(X)
        #define cosh(X) (X)->cosh(X)
        #define tanh(X) (X)->tanh(X)
        #define sech(X) (X)->sech(X)
        #define csch(X) (X)->csch(X)
        #define coth(X) (X)->coth(X)
        #define atanh(X) (X)->atanh(X)
#endif

#endif
