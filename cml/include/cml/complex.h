#ifndef CML_COMPLEX_H
#define CML_COMPLEX_H

#define _CML_COMMON_H_
#include <cml/_common/default.h>
#include <cml/_common/inline.h>
#include <cml/_common/machine.h>
#undef _CML_COMMON_H_

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

cml_complex_t cml_complex(double, double);
cml_complex_t cml_complex_polar(double, double);
cml_complex_t cml_complex_zero(void);
cml_complex_t cml_complex_nan(void);
cml_complex_t cml_complex_inf(void);
cml_complex_t cml_complex_ninf(void);
cml_complex_t cml_complex_clone(cml_complex_t);

__CML_END_DECLS

#include <cml/complex/basic.h>
#include <cml/complex/exponentiation.h>
#include <cml/complex/hyperbolic.h>
#include <cml/complex/trigonometric.h>

#define CREAL(_x) ((_x).p[0])
#define CIMAG(_x) ((_x).p[1])

#define CML_COMPLEX_P(zp) ((zp)->p)
#define CML_COMPLEX_P_REAL(zp)  ((zp)->p[0])
#define CML_COMPLEX_P_IMAG(zp)  ((zp)->p[1])
#define CML_COMPLEX_EQ(z1,z2) (((z1).p[0] == (z2).p[0]) && ((z1).p[1] == (z2).p[1]))

#define CML_SET_COMPLEX(zp,x,y) do {(zp)->p[0]=(x); (zp)->p[1]=(y);} while(0)
#define CML_SET_REAL(zp,x) do {(zp)->p[0]=(x);} while(0)
#define CML_SET_IMAG(zp,y) do {(zp)->p[1]=(y);} while(0)

#endif
