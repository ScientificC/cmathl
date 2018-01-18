#ifndef CML_H
#error "Never use <math/include/types.h> directly; include <cml.h> instead."
#endif

#ifndef CML_TYPES_H
#define CML_TYPES_H

// Quick boolean definition
#ifdef CML_NO_STDBOOL
        #include "types/bool.h"
#else
        #include <stdbool.h>
#endif

#ifdef CML_NO_STDINT
        #define mint_t int
#else
        #include <stdint.h>
        #define mint_t int32_t
#endif

#ifndef mfloat_t
        #define mfloat_t float
#endif

#include "types/real.h"
#include "types/rational.h"
#include "types/complex.h"

#endif
