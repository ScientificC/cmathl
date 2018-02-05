#ifndef CML_H
#error "Never use <cml/math/real.h> directly; include <cml.h> instead."
#endif

#ifndef CML_REAL_H
#define CML_REAL_H

typedef mfloat_t real_t;

__CML_BEGIN_DECLS

real_t real_nan();
real_t real_inf();
char* real_as_string(real_t);

__CML_END_DECLS

#include "real/basic.h"
#include "real/classification.h"
#include "real/error-gamma.h"
#include "real/exponential.h"
#include "real/nearest-integer.h"
#include "real/power.h"
#include "real/trigonometric.h"
#include "real/hyperbolic.h"

#if (defined __CML_NO_GENERIC && !defined CML_NO_ALIASES)
        #define nan() real_nan()
        #define inf() real_inf()
        #define equal(X, Y) real_equal(X, Y)
        #define isnull(X) real_isnull(X)
        #define isnatural(X) real_isnatural(X)
        #define isinteger(X) real_isinteger(X)
        #define isgreater(X, Y) real_isinteger(X, Y)
        #define isless(X, Y) real_isless(X, Y)
        #define isgreaterequal(X, Y) real_isgreaterequal(X, Y)
        #define islessequal(X, Y) real_islessequal(X, Y)
        #define ismult(X, Y) real_ismult(X, Y)
        #define add(X, Y) real_add(X, Y)
        #define prod(X, Y) real_mul(X, Y)
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
