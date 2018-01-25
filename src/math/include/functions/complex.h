#ifndef CML_COMPLEX_FUNC_H
#define CML_COMPLEX_FUNC_H

#include "complex/basic.h"
#include "complex/exponential.h"
#include "complex/hyperbolic.h"
#include "complex/trigonometric.h"

#ifndef CML_UNAMBIGUOUS_MODE
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

        #ifndef creal
                #define creal(X) (X)->p[0]
        #endif

        #ifndef cimag
                #define cimag(X) (X)->p[1]
        #endif
#endif
#endif
