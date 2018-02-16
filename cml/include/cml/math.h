#ifndef CML_H
#error "Never use <cml/math.h> directly; include <cml.h> instead."
#endif

#ifndef CML_MATH_H
#define CML_MATH_H

/* Quick boolean definition */
#ifdef CML_NO_STDBOOL
        #include "math/bool.h"
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

#include <float.h>

#ifndef mfloat_t
        #ifndef CML_NO_LONG_DOUBLE_MATH
                #define mfloat_t long double
        #else
                #define mfloat_t double
        #endif
#endif

#include "math/consts.h"
#include "math/real.h"
#include "math/complex.h"

__CML_BEGIN_DECLS

/* Definition of an arbitrary function with parameters */

struct function_struct
{
        real_t (* function) (real_t x, void * params);
        void * params;
};

typedef struct function_struct function_t;

#define FN_EVAL(F,x) (*((F)->function))(x,(F)->params)


/* Definition of an arbitrary function returning two values, r1, r2 */

struct function_fdf_struct
{
        real_t (* f) (real_t x, void * params);
        real_t (* df) (real_t x, void * params);
        void (* fdf) (real_t x, void * params, real_t * f, real_t * df);
        void * params;
};

typedef struct function_fdf_struct function_fdf_t;

#define FN_FDF_EVAL_F(FDF,x) (*((FDF)->f))(x,(FDF)->params)
#define FN_FDF_EVAL_DF(FDF,x) (*((FDF)->df))(x,(FDF)->params)
#define FN_FDF_EVAL_F_DF(FDF,x,y,dy) (*((FDF)->fdf))(x,(FDF)->params,(y),(dy))


/* Definition of an arbitrary vector-valued function with parameters */

struct function_vec_struct
{
        int (* function) (real_t x, real_t y[], void * params);
        void * params;
};

typedef struct function_vec_struct function_vec_t;

#define FN_VEC_EVAL(F,x,y) (*((F)->function))(x,y,(F)->params)

__CML_END_DECLS

#endif
