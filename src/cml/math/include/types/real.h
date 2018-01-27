#ifndef CML_REAL_H
#define CML_REAL_H

typedef mfloat_t real_t;

real_t real_nan();
real_t real_inf();
char * real_as_string(real_t);

#ifndef CML_UNAMBIGUOUS_MODE
        #define nan() real_nan()
        #define inf() real_inf()
#endif

#endif
