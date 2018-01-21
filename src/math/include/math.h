#ifndef CML_H
#error "Never use <math/include/math.h> directly; include <cml.h> instead."
#endif

#ifndef CML_MATH_H
#define CML_MATH_H

#ifndef _CML_NO_BUILTIN_TYPES
        #undef _CML_MATH_FUNC
        #define _CML_MATH_FUNC(_type, _func) ({ \
                if (_CML_B_T_C_P(_type, real) \
                    || _CML_B_T_C_P(_type, (real_t*))) { \
                        {real_ ## _func} \
                } else if (_CML_B_T_C_P(_type, complex) \
                           || _CML_B_T_C_P(_type, (complex_t*))) { \
                        {complex_ ## _func} \
                } \
        })
#endif

#include "consts.h"
#include "types.h"
#include "functions.h"

#ifndef _CML_NO_GENERIC
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
#elif !defined _CML_NO_BUILTIN_TYPES
        #define clone(X) ({ \
                typeof(X)_tmp; \
                if (_CML_B_T_C_P(typeof(X), real) \
                    || _CML_B_T_C_P(typeof(X), complex)) { \
                        _tmp = _CML_MATH_FUNC(typeof(X), clone); \
                } \
                _tmp; \
        })

        #define complex_new(X, Y) ({ \
                complex_t* _tmp; \
                if (_CML_B_T_C_P(typeof(X), real)) { \
                        _tmp = complex_new_from_reals(X, Y); \
                } else { \
                        _tmp = complex_new(X); \
                } \
                _tmp; \
        })

        #define real_new(X) ({ \
                real_t* _tmp; \
                if (_CML_B_T_C_P(typeof(X), real)) { \
                        _tmp = real_clone(X); \
                } else { \
                        _tmp = real_new(X); \
                } \
                _tmp; \
        })
#else
        #define complex_clone(X) _complex_clone(X)
        #define complex_new(X, Y) _complex_new(X, Y)
        #define complex_new_from_reals(X, Y) _complex_new_from_reals(X, Y)
        #define real_clone(X) _real_clone(X)
        #define real_new(X) _real_new(X)
#endif

#define real(X) real_new(X)
#define complex(X, Y) complex_new(X, Y)

#ifndef CML_SERIES_TOP_IT_L
#define CML_SERIES_TOP_IT_L MAXLOG*14
#endif

#endif
