#include <stdlib.h>
#include <stdio.h>
#include <cml/ieee.h>

/* A table of sign characters, 0=positive, 1=negative. We print a space
 * instead of a unary + sign for compatibility with bc
 */

static char signs[2] = {' ','-'};

void
cml_ieee754_fprintf_float(FILE *stream, const float *x)
{
        cml_ieee754_float_rep_t r;
        cml_ieee754_float_to_rep(x, &r);

        switch (r.type)
        {
        case CML_IEEE754_TYPE_CML_NAN:
                fprintf(stream, "NaN");
                break;
        case CML_IEEE754_TYPE_CML_POSINF:
                fprintf(stream, "%cInf", signs[r.sign]);
                break;
        case CML_IEEE754_TYPE_NORMAL:
                fprintf(stream, "%c1.%s*2^%d", signs[r.sign], r.mantissa, r.exponent);
                break;
        case CML_IEEE754_TYPE_DENORMAL:
                fprintf(stream, "%c0.%s*2^%d", signs[r.sign], r.mantissa, r.exponent + 1);
                break;
        case CML_IEEE754_TYPE_ZERO:
                fprintf(stream, "%c0", signs[r.sign]);
                break;
        default:
                fprintf(stream, "[non-standard IEEE float]");
        }
}

void
cml_ieee754_printf_float(const float *x)
{
        cml_ieee754_fprintf_float(stdout, x);
}

void
cml_ieee754_fprintf_double(FILE *stream, const double *x)
{
        cml_ieee754_double_rep_t r;
        cml_ieee754_double_to_rep(x, &r);

        switch (r.type)
        {
        case CML_IEEE754_TYPE_CML_NAN:
                fprintf(stream, "NaN");
                break;
        case CML_IEEE754_TYPE_CML_POSINF:
                fprintf(stream, "%cInf", signs[r.sign]);
                break;
        case CML_IEEE754_TYPE_NORMAL:
                fprintf(stream, "%c1.%s*2^%d", signs[r.sign], r.mantissa, r.exponent);
                break;
        case CML_IEEE754_TYPE_DENORMAL:
                fprintf(stream, "%c0.%s*2^%d", signs[r.sign], r.mantissa, r.exponent + 1);
                break;
        case CML_IEEE754_TYPE_ZERO:
                fprintf(stream, "%c0", signs[r.sign]);
                break;
        default:
                fprintf(stream, "[non-standard IEEE double]");
        }
}

void
cml_ieee754_printf_double(const double *x)
{
        cml_ieee754_fprintf_double(stdout, x);
}
