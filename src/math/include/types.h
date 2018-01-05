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

#ifndef cml_t
        #define cml_t float
#endif

#include "types/real.h"
#include "types/rational.h"
#include "types/complex.h"

#endif
