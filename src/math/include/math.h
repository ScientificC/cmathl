#ifndef CML_H
#error "Never use <math/include/math.h> directly; include <cml.h> instead."
#endif

#ifndef CML_MATH_H
#define CML_MATH_H

#include "consts.h"
#include "types.h"

#include "functions/complex.h"
#include "functions/real.h"

#define complex_clone(X) _complex_clone(X)
#define complex_new(X, Y) _complex_new(X, Y)
#define complex_new_from_reals(X, Y) _complex_new_from_reals(X, Y)
#define real_clone(X) _real_clone(X)
#define real_new(X) _real_new(X)

#define new(type, ...) { type ## _new(__VA_ARGS__) }

#ifndef CML_SERIES_TOP_IT_L
#define CML_SERIES_TOP_IT_L MAXLOG*14
#endif

#endif
