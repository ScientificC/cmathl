#ifndef CML_H
#error "Never use <generic/functions.h> directly; include <cml.h> instead."
#endif

#ifndef CML_GEN_FUN_H
#define CML_GEN_FUNC_H

#ifndef CML_NO_GENERIC
        #define sin(X) _Generic((X), \
                                complex_t*: complex_sin, \
                                real_t*: real_sin \
                                )(X)

        #define cos(X) _Generic((X), \
                                complex_t*: complex_cos, \
                                real_t*: real_cos \
                                )(X)

        #define tan(X) _Generic((X), \
                                complex_t*: complex_tan, \
                                real_t*: real_tan \
                                )(X)

        #define sec(X) _Generic((X), \
                                complex_t*: complex_sec, \
                                real_t*: real_sec \
                                )(X)

        #define csc(X) _Generic((X), \
                                complex_t*: complex_csc, \
                                real_t*: real_csc \
                                )(X)

        #define cot(X) _Generic((X), \
                                complex_t*: complex_cot, \
                                real_t*: real_cot \
                                )(X)

        #define sinh(X) _Generic((X), \
                                 complex_t*: complex_sinh, \
                                 real_t*: real_sinh \
                                 )(X)

        #define cosh(X) _Generic((X), \
                                 complex_t*: complex_cosh, \
                                 real_t*: real_cosh \
                                 )(X)

        #define tanh(X) _Generic((X), \
                                 complex_t*: complex_tanh, \
                                 real_t*: real_tanh \
                                 )(X)
#endif

#endif
