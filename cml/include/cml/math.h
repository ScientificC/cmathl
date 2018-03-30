#ifndef CML_MATH_H
#define CML_MATH_H

#define _CML_COMMON_H_
#include <cml/_common/default.h>
#include <cml/_common/inline.h>
#include <cml/_common/machine.h>
#undef _CML_COMMON_H_

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
#include <cml/math/exponential.h>
#include <cml/math/nearest-integer.h>
#include <cml/math/power.h>
#include <cml/math/trigonometric.h>
#include <cml/math/hyperbolic.h>

/* other needlessly compulsive abstractions */

#define CML_IS_ODD(n)  ((n) & 1)
#define CML_IS_EVEN(n) (!(CML_IS_ODD(n)))
#define CML_SIGN(x)    ((x) >= 0.0 ? 1 : -1)

/* Return nonzero if x is a real number, i.e. non NaN or infinite. */
#define CML_IS_REAL(x) (cml_isfinite(x))

/* Definition of an arbitrary function with parameters */

typedef struct
{
        double (* function)(double x, void *params);
        void *params;
} cml_function_t;

#define CML_FN_EVAL(F,x) (*((F)->function))(x,(F)->params)


/* Definition of an arbitrary function returning two values, r1, r2 */

typedef struct
{
        double (* f)(double x, void *params);
        double (* df)(double x, void *params);
        void (* fdf)(double x, void *params, double * f, double * df);
        void *params;
} cml_function_fdf_t;

#define CML_FN_FDF_EVAL_F(FDF,x) (*((FDF)->f))(x,(FDF)->params)
#define CML_FN_FDF_EVAL_DF(FDF,x) (*((FDF)->df))(x,(FDF)->params)
#define CML_FN_FDF_EVAL_F_DF(FDF,x,y,dy) (*((FDF)->fdf))(x,(FDF)->params,(y),(dy))


/* Definition of an arbitrary vector-valued function with parameters */

typedef struct
{
        int (* function)(double x, double y[], void *params);
        void *params;
} cml_function_vec_t;

#define CML_FN_VEC_EVAL(F,x,y) (*((F)->function))(x,y,(F)->params)

__CML_END_DECLS

#endif
