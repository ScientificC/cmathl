#ifndef CML_H
#error "Never use <math/include/math.h> directly; include <cml.h> instead."
#endif

#ifndef CML_MATH_H
#define CML_MATH_H

#include "consts.h"
#include "types.h"
#include "functions.h"

#ifdef _CML_NO_GENERIC
        #define complex_clone(X) _complex_clone(X)
        #define complex_new(X, Y) _complex_new(X, Y)
        #define complex_new_from_reals(X, Y) _complex_new_from_reals(X, Y)
        #define real_clone(X) _real_clone(X)
        #define real_new(X) _real_new(X)
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

#define real(X) real_new(X)
#define complex(X, Y) complex_new(X, Y)
#define new(type, ...) (type ## _t*) { type ## _new(__VA_ARGS__) }

#ifndef CML_SERIES_TOP_IT_L
#define CML_SERIES_TOP_IT_L MAXLOG*14
#endif

#endif
