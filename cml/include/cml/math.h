#ifndef CML_MATH_H
#define CML_MATH_H

#define CML_H
#include <cml/default.h>
#include <cml/inline.h>
#include <cml/machine.h>

#include <cml/minmax.h>

/* Quick boolean definition */
#ifdef CML_NO_STDBOOL
        #include <cml/math/bool.h>
#else
        #include <stdbool.h>
#endif

#ifndef mint_t
        #ifdef CML_NO_STDINT
                #define mint_t int
        #else
                #include <stdint.h>
                #define mint_t int32_t
        #endif
#endif

#define __CML_MATH_NAME(_f) _f

/*
 #ifdef CML_LONG_DOUBLE_MATH
 #undef __CML_MATH_NAME
 #define __CML_MATH_NAME(_f) _f ## l
 #endif
 */

#include <cml/math/consts.h>
#include <cml/math/real.h>
#include <cml/math/complex.h>

__CML_BEGIN_DECLS

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
