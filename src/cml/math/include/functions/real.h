#ifndef CML_REAL_FUNC_H
#define CML_REAL_FUNC_H

#include "real/basic.h"
#include "real/classification.h"
#include "real/error-gamma.h"
#include "real/exponential.h"
#include "real/nearest-integer.h"
#include "real/power.h"
#include "real/trigonometric.h"
#include "real/hyperbolic.h"

#if (defined _CML_NO_GENERIC && !defined CML_NO_ALIASES)
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
        #define ln(X) real_log(X)
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
#endif
