#ifndef _CML_COMMON_H_
#error "Never use <cml/_common/inline.h> directly; include <cml.h> instead."
#endif

#ifndef CML_INLINE_H
#define CML_INLINE_H

#ifdef _MSC_VER
        #define __CML_INLINE __forceinline
#else
        #define __CML_INLINE inline __attribute((always_inline))
#endif

/* Use `extern inline` for C99 or later */
#ifdef PREDEF_STANDARD_C99
        #define __CML_EXTERN_INLINE extern __CML_INLINE
#else
        #undef __CML_INLINE

        #define __CML_INLINE
        #define __CML_EXTERN_INLINE
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER) || defined(WIN32)
        #define __CML_API __declspec(dllexport)
#endif

#endif
