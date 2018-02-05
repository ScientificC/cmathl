#ifndef CML_H
#error "Never use <cml/math/complex.h> directly; include <cml.h> instead."
#endif

#ifndef CML_COMPLEX_H
#define CML_COMPLEX_H

typedef struct _complex
{
        union
        {
                real_t p[2];
                real_t parts[2];
                struct
                {
                        real_t re;
                        real_t im;
                };
                struct real_t
                {
                        real_t real;
                        real_t imaginary;
                };
        };
} complex_t;

__CML_BEGIN_DECLS

complex_t complex(real_t, real_t);
complex_t complex_polar(real_t, real_t);
complex_t complex_zero();
complex_t complex_nan();
complex_t complex_inf();
complex_t complex_ninf();
complex_t complex_clone(complex_t);
char* complex_as_string(complex_t);

__CML_END_DECLS

#include "complex/basic.h"
#include "complex/error.h"
#include "complex/exponentiation.h"
#include "complex/hyperbolic.h"
#include "complex/trigonometric.h"

#ifndef CML_NO_ALIASES
        #define cnan() complex_nan()
        #define cinf() complex_inf()
        #define cequal(X, Y) complex_equal(X, Y)
        #define cisnull(X) complex_isnull(X)
        #define cismult(X, Y) complex_ismult(X, Y)
        #define cadd(X, Y) complex_add(X, Y)
        #define cprod(X, Y) complex_mul(X, Y)
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
                #define creal(X) (X).p[0]
        #endif

        #ifndef cimag
                #define cimag(X) (X).p[1]
        #endif
#endif

#endif
