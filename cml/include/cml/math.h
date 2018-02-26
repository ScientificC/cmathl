#ifndef CML_MATH_H
#define CML_MATH_H

#define CML_H
#include <cml/default.h>
#include <cml/inline.h>
#include <cml/machine.h>

#include <cml/minmax.h>

#define __CML_MATH_NAME(_f) _f

#include <cml/math/consts.h>

__CML_BEGIN_DECLS

double cml_nan();
double cml_inf();
double cml_ninf();
char* cml_as_string(double);

#include <cml/math/basic.h>
#include <cml/math/classification.h>
#include <cml/math/error-gamma.h>
#include <cml/math/exponential.h>
#include <cml/math/nearest-integer.h>
#include <cml/math/power.h>
#include <cml/math/trigonometric.h>
#include <cml/math/hyperbolic.h>

#if (defined __CML_NO_GENERIC && !defined CML_NO_ALIASES)
        #define nan() cml_nan()
        #define inf() cml_inf()

        #define equal(X, Y) cml_equal(X, Y)
        #define isnull(X) cml_isnull(X)
        #define isnatural(X) cml_isnatural(X)
        #define isinteger(X) cml_isinteger(X)
        #define isgreater(X, Y) cml_isinteger(X, Y)
        #define isless(X, Y) cml_isless(X, Y)
        #define isgreaterequal(X, Y) cml_isgreaterequal(X, Y)
        #define islessequal(X, Y) cml_islessequal(X, Y)
        #define ismult(X, Y) cml_ismult(X, Y)

        #define add(X, Y) cml_add(X, Y)
        #define mul(X, Y) cml_mul(X, Y)
        #define sub(X, Y) cml_sub(X, Y)
        #define div(X, Y) cml_div(X, Y)
        #define sgn(X, Y) cml_sgn(X, Y)
        #define abs(X) cml_abs(X)
        #define floor(X) cml_floor(X)
        #define ceil(X) cml_ceil(X)
        #define div_e(X) cml_div_e(X)
        #define mod(X) cml_mod(X)
        #define inverse(X) cml_inverse(X)
        #define opposite(X) cml_opposite(X)
        #define ared(X) cml_ared(X)
        #define hypot(X, Y) cml_hypot(X, Y)
        #define fact(X) cml_fact(X)

        #define error(X) cml_error(X)
        #define gamma(X) cml_gamma(X)

        #define exp(X) cml_exp(X)
        #define ln(X) cml_log(X)
        #define log(X) cml_log(X)
        #define log_b(X, Y) cml_log_b(X, Y)
        #define log1p(X) cml_log1p(X)

        #define powi(X, Y) cml_pow_int(X, Y)
        #define powui(X, Y) cml_pow_uint(X, Y)
        #define pow(X, Y) cml_pow(X, Y)
        #define root(X) cml_root(X)
        #define sqrt(X) cml_sqrt(X)

        #define sin(X) cml_sin(X)
        #define cos(X) cml_cos(X)
        #define tan(X) doublean(X)
        #define sec(X) cml_sec(X)
        #define csc(X) cml_csc(X)
        #define cot(X) cml_cot(X)
        #define asin(X) cml_asin(X)
        #define acos(X) cml_acos(X)
        #define atan(X) cml_atan(X)
        #define atan2(X, Y) cml_atan2(X, Y)

        #define sinh(X) cml_sinh(X)
        #define cosh(X) cml_cosh(X)
        #define tanh(X) doubleanh(X)
        #define sech(X) cml_sech(X)
        #define csch(X) cml_csch(X)
        #define coth(X) cml_coth(X)
        #define asinh(X) cml_asinh(X)
        #define acosh(X) cml_acosh(X)
        #define atanh(X) cml_atanh(X)
#endif

/* Definition of an arbitrary function with parameters */

struct cml_function_struct
{
        double (* function) (double x, void * params);
        void * params;
};

typedef struct cml_function_struct cml_function_t;

#define FN_EVAL(F,x) (*((F)->function))(x,(F)->params)


/* Definition of an arbitrary function returning two values, r1, r2 */

struct cml_function_fdf_struct
{
        double (* f) (double x, void * params);
        double (* df) (double x, void * params);
        void (* fdf) (double x, void * params, double * f, double * df);
        void * params;
};

typedef struct cml_function_fdf_struct cml_function_fdf_t;

#define FN_FDF_EVAL_F(FDF,x) (*((FDF)->f))(x,(FDF)->params)
#define FN_FDF_EVAL_DF(FDF,x) (*((FDF)->df))(x,(FDF)->params)
#define FN_FDF_EVAL_F_DF(FDF,x,y,dy) (*((FDF)->fdf))(x,(FDF)->params,(y),(dy))


/* Definition of an arbitrary vector-valued function with parameters */

struct cml_function_vec_struct
{
        int (* function) (double x, double y[], void * params);
        void * params;
};

typedef struct cml_function_vec_struct cml_function_vec_t;

#define FN_VEC_EVAL(F,x,y) (*((F)->function))(x,y,(F)->params)

__CML_END_DECLS

#endif
