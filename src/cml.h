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

#ifdef __cplusplus__
        #ifdef __cplusplus
                #if __cplusplus >= 199901L
                        #define PREDEF_STANDARD_C99
                        #if __cplusplus >= 201112L
                                #define PREDEF_STANDARD_C11
                        #endif
                #endif
        #endif
#endif

#ifdef _MSC_VER
        #define _CML_INLINE __forceinline
#else
        #define _CML_INLINE inline __attribute__((always_inline))
#endif

/* Use `extern inline` for C99 or later */
#ifdef PREDEF_STANDARD_C99
        #define _CML_EXTERN_INLINE extern _CML_INLINE
#else
        #undef _CML_EXTERN_INLINE
        #undef CML_DOUBLE_PRECISION
        #undef mfloat_t

        #define _CML_EXTERN_INLINE
        #define CML_DOUBLE_PRECISION
        #define mfloat_t double
#endif

#ifndef PREDEF_STANDARD_C11
        #undef _CML_NO_GENERIC
        #define _CML_NO_GENERIC
#endif

#define _CML_ARGS_FIRST(A, ...) A

#ifndef __type
#define __type(__e, __t)                                                \
        __builtin_types_compatible_p(__typeof(__e), __t)
#endif

#ifndef __same_type
        #define __same_type(__a, __b) \
        __builtin_types_compatible_p(__typeof(__a), __typeof(__b))
#endif

/* #define _CML_NO_EXTENSIONS */

#if !(defined _CML_NO_GENERIC && defined _CML_NO_EXTENSIONS)
        #define CML_NO_FUNCTION_POINTER
#endif

#include "math/include/math.h"

#ifndef CML_NO_EASING_FUNCTIONS
        #include "easings/include/functions.h"
#endif

#include "version.h"

#endif
