#ifndef CML_H
#error "Never use <cml/math/functions.h> directly; include <cml.h> instead."
#endif

#ifndef CML_MATH_FUNC_H
#define CML_MATH_FUNC_H

#include "functions/complex.h"
#include "functions/real.h"

#if !(defined CML_UNAMBIGUOUS_MODE || defined _CML_NO_GENERIC)
        #include "functions/generic.h"
#endif

#endif
