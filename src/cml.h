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

#if !defined PREDEF_STANDARD_C11 || !defined _Generic
        #define _CML_NO_GENERIC
#endif

#ifndef __builtin_types_compatible_p
        #define _CML_NO_BUILTIN_TYPES
#else
        #define _CML_B_T_C_P __builtin_types_compatible_p
#endif

#ifndef typeof
#define typeof(X) __typeof__(X)
#endif

#if !defined _CML_NO_GENERIC || !defined _CML_NO_BUILTIN_TYPES
        #undef CML_NO_FUNCTION_POINTER
        #define CML_NO_FUNCTION_POINTER
#endif

#include "math/include/math.h"

#ifdef CML_SERIES_RESOLVER
        #include "utils/include/series_resolver.h"
#endif

#include "version.h"

#endif
