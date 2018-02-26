#ifndef CML_COMPLEX_H
#define CML_COMPLEX_H

#define CML_H
#include <cml/default.h>
#include <cml/inline.h>
#include <cml/machine.h>

typedef struct
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
} cml_complex_long_double_t;

typedef struct
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
} cml_complex_t;

typedef struct
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
} cml_complex_float_t;

__CML_BEGIN_DECLS

cml_complex_t complex(double, double);
cml_complex_t cml_complex_polar(double, double);
cml_complex_t cml_complex_zero();
cml_complex_t cml_complex_nan();
cml_complex_t cml_complex_inf();
cml_complex_t cml_complex_ninf();
cml_complex_t cml_complex_clone(cml_complex_t);
char* cml_complex_as_string(cml_complex_t);

__CML_END_DECLS

#include <cml/complex/basic.h>
#include <cml/complex/error.h>
#include <cml/complex/exponentiation.h>
#include <cml/complex/hyperbolic.h>
#include <cml/complex/trigonometric.h>

#ifndef CML_NO_ALIASES
        #define creal(X) (X).re
        #define cimag(X) (X).im

        #define cpolar(X, Y) cml_complex_polar(X, Y)
        #define czero() cml_complex_zero()
        #define cnan() cml_complex_nan()
        #define cinf() cml_complex_inf()
        #define cninf() cml_complex_inf()
        #define cclone(X) cml_complex_clone(X)

        #define cabs(X) cml_complex_abs(X)
        #define carg(X) cml_complex_arg(X)
        #define clogabs(X) cml_complex_logabs(X)

        #define cadd(X, Y) cml_complex_add(X, Y)
        #define cconj(X) cml_complex_conj(X)
        #define cdiv(X, Y) cml_complex_div(X, Y)
        #define cinverse(X) cml_complex_inverse(X)
        #define cmul(X, Y) cml_complex_mul(X, Y)
        #define cscalarmul(X, Y) cml_complex_scalar_mul(X, Y)
        #define csub(X, Y) cml_complex_sub(X, Y)
        #define caddr(X, Y) cml_complex_add_real(X, Y)
        #define csubr(X, Y) cml_complex_sub_real(X, Y)
        #define cmulr(X, Y) cml_complex_mul_real(X, Y)
        #define cdivr(X, Y) cml_complex_div_real(X, Y)
        #define caddi(X, Y) cml_complex_add_imag(X, Y)
        #define csubi(X, Y) cml_complex_sub_imag(X, Y)
        #define cmuli(X, Y) cml_complex_mul_imag(X, Y)
        #define cdivi(X, Y) cml_complex_div_imag(X, Y)

        #define cerror(X) cml_complex_error(X)

        #define cexp(X) cml_complex_exp(X)
        #define clogb(X, Y) cml_complex_log_b(X, Y)
        #define clog(X) cml_complex_log(X)
        #define csqrt(X) cml_complex_sqrt(X)
        #define csqrtr(X) cml_complex_sqrt_real(X)
        #define cpow(X, Y) cml_complex_pow(X, Y)
        #define cpowr(X, Y) cml_complex_pow_real(X, Y)

        #define ccosh(X) cml_complex_cosh(X)
        #define csinh(X) cml_complex_sinh(X)
        #define ctanh(X) cml_complex_tanh(X)
        #define csech(X) cml_complex_sech(X)
        #define ccsch(X) cml_complex_csch(X)
        #define ccoth(X) cml_complex_coth(X)
        #define casinh(X) cml_complex_asinh(X)
        #define cacosh(X) cml_complex_acosh(X)
        #define cacoshr(X) cml_complex_acosh_real(X)
        #define catanh(X) cml_complex_atanh(X)
        #define catanhr(X) cml_complex_atanh_real(X)
        #define casech(X) cml_complex_asech(X)
        #define cacsch(X) cml_complex_acsch(X)
        #define cacoth(X) cml_complex_acoth(X)

        #define ccos(X) cml_complex_cos(X)
        #define ccot(X) cml_complex_cot(X)
        #define ccsc(X) cml_complex_csc(X)
        #define csec(X) cml_complex_sec(X)
        #define csin(X) cml_complex_sin(X)
        #define ctan(X) cml_complex_tan(X)

        #define casin(X) cml_complex_asin(X)
        #define casinr(X) cml_complex_asin_real(X)
        #define cacos(X) cml_complex_acos(X)
        #define cacosr(X) cml_complex_acos_real(X)
        #define catan(X) cml_complex_atan(X)
        #define casec(X) cml_complex_asec(X)
        #define casecr(X) cml_complex_asec_real(X)
        #define cacsc(X) cml_complex_acsc(X)
        #define cacscr(X) cml_complex_acsc_real(X)
        #define cacot(X) cml_complex_acot(X)
#endif
#endif
