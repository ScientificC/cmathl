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

#include <math/include/math.h>
#include <generic/functions.h>

#ifdef CML_NO_GENERIC
/* Only work with the macros defined in <math/include/math.h> */
#else
        #undef clone
        #undef complex_new
        #undef real_new

        #define clone(X) _Generic((X), \
                                  complex_t*: _complex_clone, \
                                  real_t*: _real_clone \
                                  )(X)

        #define complex_new(X, Y) _Generic((X), \
                                   default: _Generic((Y), \
                                             default: _complex_new \
                                                     ), \
                                           mfloat_t: _Generic((Y), \
                                                      default: _complex_new, \
                                                              mfloat_t: _complex_new \
                                                              ), \
                                           real_t*: _Generic((Y), \
                                                     default: _complex_new_from_reals, \
                                                             real_t*: _complex_new_from_reals \
                                                             ) \
                                           )(X, Y)

        #define real_new(X) _Generic((X), \
                             default: _real_new, \
                                     mfloat_t: _real_new, \
                                     real_t*: _real_clone \
                                     )(X)
#endif

#ifdef CML_SERIES_RESOLVER
        #include <utils/include/series_resolver.h>
#endif

#endif
