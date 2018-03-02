#ifndef CML_H
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
        #define __CML_EXTERN_INLINE
#endif
#endif
