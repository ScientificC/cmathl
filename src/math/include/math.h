#ifndef CML_H
#error "Never use <math/include/math.h> directly; include <cml.h> instead."
#endif

#ifndef CML_MATH_H
#define CML_MATH_H

#include "consts.h"
#include "types.h"
#include "functions.h"

#ifndef complex_clone
        #define complex_clone(X) _complex_clone(X)
#endif

#ifndef complex_new
        #define complex_new(X, Y) _complex_new(X, Y)
#endif

#define complex(X, Y) complex_new(X, Y)

#ifndef CML_SERIES_TOP_IT_L
#define CML_SERIES_TOP_IT_L MAXLOG*14
#endif

#endif
