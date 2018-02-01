#ifndef CML_H
#error "Never use <cml/math/types.h> directly; include <cml.h> instead."
#endif

#ifndef CML_MATH_TYPES_H
#define CML_MATH_TYPES_H

/* Quick boolean definition */
#ifdef CML_NO_STDBOOL
        #include "types/bool.h"
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

#include "types/real.h"
#include "types/complex.h"

#endif
