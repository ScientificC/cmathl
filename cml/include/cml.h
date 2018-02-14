#ifndef CML_H
#define CML_H

#include "cml/config.h"
#include "cml/default.h"
#include "cml/errno.h"
#include "cml/ieee.h"
#include "cml/inline.h"
#include "cml/machine.h"

#ifndef PREDEF_STANDARD_C11
        #undef __CML_NO_GENERIC
        #define __CML_NO_GENERIC
#endif

#define __CML_ARGS_FIRST(A, ...) A

#ifndef __CML_TYPE
        #define __CML_TYPE(__e, __t) \
                __builtin_types_compatible_p(__typeof(__e), __t)
#endif

#ifndef __CML_SAME_TYPE
        #define __CML_SAME_TYPE(__a, __b) \
        __builtin_types_compatible_p(__typeof(__a), __typeof(__b))
#endif


#if defined CML_NO_ALIASES || defined __CML_NO_GENERIC
        #include "cml/math.h"
#else
        #include "cml/tgmath.h"
#endif

#include "cml/diff.h"

#ifndef CML_NO_STRUCTURES
        #include "cml/structures.h"
#endif

#ifndef CML_NO_EASING_FUNCTIONS
        #include "cml/easings.h"
#endif

#endif
