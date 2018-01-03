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

#include "types/types.h"
#include "constants/consts.h"
#include "functions/functions.h"
#include "functions/real.h"
#include "functions/complex.h"

#ifndef CML_SERIES_TOP_IT_L
#define CML_SERIES_TOP_IT_L MAXLOG*14
#endif

#endif
