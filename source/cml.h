#ifndef CML_H
#define CML_H

/* Check C standard */
#ifdef __STDC__
  #define PREDEF_STANDARD_C89
  #ifdef __STDC_VERSION__
    #if __STDC_VERSION__ >= 199901L
      #define PREDEF_STANDARD_C99
    #endif
  #endif
#endif

/* Use `extern inline` for C99 or later */
#ifdef PREDEF_STANDARD_C99
#define CML_EXTERN_INLINE extern inline
#else
#define CML_EXTERN_INLINE
#endif

#include "math/include/math.h"

#ifdef CML_SERIES_RESOLVER
  #include "utils/include/series_resolver.h"
#endif

#endif
