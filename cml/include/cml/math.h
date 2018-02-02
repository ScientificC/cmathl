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

#ifndef mfloat_t
        #define mfloat_t double
#endif

#include "math/consts.h"
#include "math/real.h"
#include "math/complex.h"

#ifndef CML_SERIES_TOP_IT_L
        #define CML_SERIES_TOP_IT_L MAXLOG*14
#endif

#endif
