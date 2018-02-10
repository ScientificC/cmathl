#ifndef CML_H
#error "Never use <cml/inline.h> directly; include <cml.h> instead."
#endif

#ifndef CML_INLINE_H
#define CML_INLINE_H

#ifdef _MSC_VER
        #define __CML_INLINE __forceinline
#else
        #define __CML_INLINE inline __attribute__((always_inline))
#endif

/* Use `extern inline` for C99 or later */
#ifdef PREDEF_STANDARD_C99
        #define __CML_EXTERN_INLINE extern __CML_INLINE
#else
        #undef __CML_EXTERN_INLINE
        #undef CML_SINGLE_PRECISION
        #undef mfloat_t

        #define __CML_EXTERN_INLINE
        #define mfloat_t double
#endif
#endif
