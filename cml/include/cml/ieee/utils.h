#ifndef CML_H
#error "Never use <cml/ieee/utils.h> directly; include <cml.h> instead."
#endif

#ifndef CML_IEEE_UTILS_H
#define CML_IEEE_UTILS_H

#include <stdio.h>

__CML_BEGIN_DECLS

enum {
        CML_IEEE_TYPE_NAN = 1,
        CML_IEEE_TYPE_INF = 2,
        CML_IEEE_TYPE_NORMAL = 3,
        CML_IEEE_TYPE_DENORMAL = 4,
        CML_IEEE_TYPE_ZERO = 5
};

typedef struct
{
        int sign;
        char mantissa[24]; /* Actual bits are 0..22, element 23 is \0 */
        int exponent;
        int type;
} ieee_float_rep_t;

typedef struct
{
        int sign;
        char mantissa[53]; /* Actual bits are 0..51, element 52 is \0 */
        int exponent;
        int type;
} ieee_double_rep_t;


void ieee_printf_float(const float *x);
void ieee_printf_double(const double *x);

void ieee_fprintf_float(FILE *stream, const float *x);
void ieee_fprintf_double(FILE *stream, const double *x);

void ieee_float_to_rep(const float *x, ieee_float_rep_t *r);
void ieee_double_to_rep(const double *x, ieee_double_rep_t *r);

enum {
        CML_IEEE_SINGLE_PRECISION = 1,
        CML_IEEE_DOUBLE_PRECISION = 2,
        CML_IEEE_EXTENDED_PRECISION = 3
};

enum {
        CML_IEEE_ROUND_TO_NEAREST = 1,
        CML_IEEE_ROUND_DOWN = 2,
        CML_IEEE_ROUND_UP = 3,
        CML_IEEE_ROUND_TO_ZERO = 4
};

enum {
        CML_IEEE_MASK_INVALID = 1,
        CML_IEEE_MASK_DENORMALIZED = 2,
        CML_IEEE_MASK_DIVISION_BY_ZERO = 4,
        CML_IEEE_MASK_OVERFLOW = 8,
        CML_IEEE_MASK_UNDERFLOW = 16,
        CML_IEEE_MASK_ALL = 31,
        CML_IEEE_TRAP_INEXACT = 32
};

void ieee_env_setup(void);
int ieee_read_mode_string(const char *description, int *precision,
                          int *rounding, int *exception_mask);
int ieee_set_mode(int precision, int rounding, int exception_mask);

__CML_END_DECLS

#endif
