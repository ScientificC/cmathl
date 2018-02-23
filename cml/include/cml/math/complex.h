#ifndef CML_H
#error "Never use <cml/math/complex.h> directly; include <cml.h> instead."
#endif

#ifndef CML_COMPLEX_H
#define CML_COMPLEX_H

typedef struct _complex_long_double
{
        union
        {
                long double p[2];
                long double parts[2];
                struct
                {
                        long double re;
                        long double im;
                };
                struct
                {
                        long double real;
                        long double imaginary;
                };
        };
} complex_long_double_t;

typedef struct _complex
{
        union
        {
                double p[2];
                double parts[2];
                struct
                {
                        double re;
                        double im;
                };
                struct
                {
                        double real;
                        double imaginary;
                };
        };
} complex_t;

typedef struct _complex_float
{
        union
        {
                float p[2];
                float parts[2];
                struct
                {
                        float re;
                        float im;
                };
                struct
                {
                        float real;
                        float imaginary;
                };
        };
} complex_float_t;

__CML_BEGIN_DECLS

complex_t complex(double, double);
complex_t complex_polar(double, double);
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
        #define creal(X) (X).re
        #define cimag(X) (X).im

        #define cpolar(X, Y) complex_polar(X, Y)
        #define czero() complex_zero()
        #define cnan() complex_nan()
        #define cinf() complex_inf()
        #define cninf() complex_inf()
        #define cclone(X) complex_clone(X)

        #define cabs(X) complex_abs(X)
        #define carg(X) complex_arg(X)
        #define clogabs(X) complex_logabs(X)

        #define cadd(X, Y) complex_add(X, Y)
        #define cconj(X) complex_conj(X)
        #define cdiv(X, Y) complex_div(X, Y)
        #define cinverse(X) complex_inverse(X)
        #define cmul(X, Y) complex_mul(X, Y)
        #define cscalarmul(X, Y) complex_scalar_mul(X, Y)
        #define csub(X, Y) complex_sub(X, Y)
        #define caddr(X, Y) complex_add_real(X, Y)
        #define csubr(X, Y) complex_sub_real(X, Y)
        #define cmulr(X, Y) complex_mul_real(X, Y)
        #define cdivr(X, Y) complex_div_real(X, Y)
        #define caddi(X, Y) complex_add_imag(X, Y)
        #define csubi(X, Y) complex_sub_imag(X, Y)
        #define cmuli(X, Y) complex_mul_imag(X, Y)
        #define cdivi(X, Y) complex_div_imag(X, Y)

        #define cerror(X) complex_error(X)

        #define cexp(X) complex_exp(X)
        #define clogb(X, Y) complex_log_b(X, Y)
        #define clog(X) complex_log(X)
        #define csqrt(X) complex_sqrt(X)
        #define csqrtr(X) complex_sqrt_real(X)
        #define cpow(X, Y) complex_pow(X, Y)
        #define cpowr(X, Y) complex_pow_real(X, Y)

        #define ccosh(X) complex_cosh(X)
        #define csinh(X) complex_sinh(X)
        #define ctanh(X) complex_tanh(X)
        #define csech(X) complex_sech(X)
        #define ccsch(X) complex_csch(X)
        #define ccoth(X) complex_coth(X)
        #define casinh(X) complex_asinh(X)
        #define cacosh(X) complex_acosh(X)
        #define cacoshr(X) complex_acosh_real(X)
        #define catanh(X) complex_atanh(X)
        #define catanhr(X) complex_atanh_real(X)
        #define casech(X) complex_asech(X)
        #define cacsch(X) complex_acsch(X)
        #define cacoth(X) complex_acoth(X)

        #define ccos(X) complex_cos(X)
        #define ccot(X) complex_cot(X)
        #define ccsc(X) complex_csc(X)
        #define csec(X) complex_sec(X)
        #define csin(X) complex_sin(X)
        #define ctan(X) complex_tan(X)

        #define casin(X) complex_asin(X)
        #define casinr(X) complex_asin_real(X)
        #define cacos(X) complex_acos(X)
        #define cacosr(X) complex_acos_real(X)
        #define catan(X) complex_atan(X)
        #define casec(X) complex_asec(X)
        #define casecr(X) complex_asec_real(X)
        #define cacsc(X) complex_acsc(X)
        #define cacscr(X) complex_acsc_real(X)
        #define cacot(X) complex_acot(X)
#endif
#endif
