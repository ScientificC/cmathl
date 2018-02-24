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

double real_nan();
double real_inf();
double real_ninf();
char* real_as_string(double);

#include <cml/math/basic.h>
#include <cml/math/classification.h>
#include <cml/math/error-gamma.h>
#include <cml/math/exponential.h>
#include <cml/math/nearest-integer.h>
#include <cml/math/power.h>
#include <cml/math/trigonometric.h>
#include <cml/math/hyperbolic.h>

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
        #define mul(X, Y) real_mul(X, Y)
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
        #define hypot(X, Y) real_hypot(X, Y)
        #define fact(X) real_fact(X)

        #define error(X) real_error(X)
        #define gamma(X) real_gamma(X)

        #define exp(X) real_exp(X)
        #define ln(X) real_log(X)
        #define log(X) real_log(X)
        #define log_b(X, Y) real_log_b(X, Y)
        #define log1p(X) real_log1p(X)

        #define powi(X, Y) real_pow_int(X, Y)
        #define powui(X, Y) real_pow_uint(X, Y)
        #define pow(X, Y) real_pow(X, Y)
        #define root(X) real_root(X)
        #define sqrt(X) real_sqrt(X)

        #define sin(X) real_sin(X)
        #define cos(X) real_cos(X)
        #define tan(X) doublean(X)
        #define sec(X) real_sec(X)
        #define csc(X) real_csc(X)
        #define cot(X) real_cot(X)
        #define asin(X) real_asin(X)
        #define acos(X) real_acos(X)
        #define atan(X) real_atan(X)
        #define atan2(X, Y) real_atan2(X, Y)

        #define sinh(X) real_sinh(X)
        #define cosh(X) real_cosh(X)
        #define tanh(X) doubleanh(X)
        #define sech(X) real_sech(X)
        #define csch(X) real_csch(X)
        #define coth(X) real_coth(X)
        #define asinh(X) real_asinh(X)
        #define acosh(X) real_acosh(X)
        #define atanh(X) real_atanh(X)
#endif

/* Definition of an arbitrary function with parameters */

struct function_struct
{
        double (* function) (double x, void * params);
        void * params;
};

typedef struct function_struct function_t;

#define FN_EVAL(F,x) (*((F)->function))(x,(F)->params)


/* Definition of an arbitrary function returning two values, r1, r2 */

struct function_fdf_struct
{
        double (* f) (double x, void * params);
        double (* df) (double x, void * params);
        void (* fdf) (double x, void * params, double * f, double * df);
        void * params;
};

typedef struct function_fdf_struct function_fdf_t;

#define FN_FDF_EVAL_F(FDF,x) (*((FDF)->f))(x,(FDF)->params)
#define FN_FDF_EVAL_DF(FDF,x) (*((FDF)->df))(x,(FDF)->params)
#define FN_FDF_EVAL_F_DF(FDF,x,y,dy) (*((FDF)->fdf))(x,(FDF)->params,(y),(dy))


/* Definition of an arbitrary vector-valued function with parameters */

struct function_vec_struct
{
        int (* function) (double x, double y[], void * params);
        void * params;
};

typedef struct function_vec_struct function_vec_t;

#define FN_VEC_EVAL(F,x,y) (*((F)->function))(x,y,(F)->params)

__CML_END_DECLS

#endif
