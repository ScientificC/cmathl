#ifndef CML_H
#define CML_H

/* Check C standard */
#ifdef __STDC__
        #define PREDEF_STANDARD_C89
        #ifdef __STDC_VERSION__
                #if __STDC_VERSION__ >= 199901L
                        #define PREDEF_STANDARD_C99
                        #if __STDC_VERSION__ >= 201112L
                                #define PREDEF_STANDARD_C11
                        #endif
                #endif
        #endif
#endif

/* Use `extern inline` for C99 or later */
#ifdef PREDEF_STANDARD_C99
        #define CML_EXTERN_INLINE extern inline __attribute__((always_inline))
#else
        #define CML_EXTERN_INLINE
        #define CML_DOUBLE_PRECISION
        #define mfloat_t double
#endif

#ifndef _Generic
        #undef _CML_NO_GENERIC
        #undef _CML_NO_GENERIC
#endif

#ifndef typeof
        #define typeof(X) __typeof__(X)
#endif

#define _CML_B_T_C_P(X, Y) __builtin_types_compatible_p(X, Y)

#ifndef __same_type
        #define __same_type(a, b) __builtin_types_compatible_p(typeof(a), typeof(b))
#endif

#ifdef _CML_NO_GENERIC
        #define CML_NO_FUNCTION_POINTER
#endif

#include "math/include/math.h"

#ifndef CML_NO_EASING_FUNCTIONS
        #include "easings/include/functions.h"
#endif

#ifdef CML_SERIES_RESOLVER
        #include "utils/include/series_resolver.h"
#endif

#include "version.h"

#endif
