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

#ifndef PREDEF_STANDARD_C11
        #define CML_NO_GENERIC
#endif

#ifndef CML_NO_GENERIC
        #define CML_NO_FUNCTION_POINTER
#endif

#ifdef __cplusplus
extern "C"
{
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

#define real(X) real_new(X);
#define complex(X, Y) complex_new(X, Y);

#ifdef CML_SERIES_RESOLVER
        #include <utils/include/series_resolver.h>
#endif

#ifdef __cplusplus
}
#endif

#endif
