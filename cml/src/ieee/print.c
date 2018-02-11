#include <stdlib.h>
#include <stdio.h>
#include <cml.h>

/* A table of sign characters, 0=positive, 1=negative. We print a space
   instead of a unary + sign for compatibility with bc */

static char signs[2] = {' ','-'};

void
ieee_fprintf_float(FILE *stream, const float *x)
{
        ieee_float_rep_t r;
        ieee_float_to_rep(x, &r);

        switch (r.type)
        {
        case CML_IEEE_TYPE_NAN:
                fprintf(stream, "NaN");
                break;
        case CML_IEEE_TYPE_INF:
                fprintf(stream, "%cInf", signs[r.sign]);
                break;
        case CML_IEEE_TYPE_NORMAL:
                fprintf(stream, "%c1.%s*2^%d", signs[r.sign], r.mantissa, r.exponent);
                break;
        case CML_IEEE_TYPE_DENORMAL:
                fprintf(stream, "%c0.%s*2^%d", signs[r.sign], r.mantissa, r.exponent + 1);
                break;
        case CML_IEEE_TYPE_ZERO:
                fprintf(stream, "%c0", signs[r.sign]);
                break;
        default:
                fprintf(stream, "[non-standard IEEE float]");
        }
}

void
ieee_printf_float(const float *x)
{
        ieee_fprintf_float(stdout, x);
}

void
ieee_fprintf_double(FILE *stream, const double *x)
{
        ieee_double_rep_t r;
        ieee_double_to_rep(x, &r);

        switch (r.type)
        {
        case CML_IEEE_TYPE_NAN:
                fprintf(stream, "NaN");
                break;
        case CML_IEEE_TYPE_INF:
                fprintf(stream, "%cInf", signs[r.sign]);
                break;
        case CML_IEEE_TYPE_NORMAL:
                fprintf(stream, "%c1.%s*2^%d", signs[r.sign], r.mantissa, r.exponent);
                break;
        case CML_IEEE_TYPE_DENORMAL:
                fprintf(stream, "%c0.%s*2^%d", signs[r.sign], r.mantissa, r.exponent + 1);
                break;
        case CML_IEEE_TYPE_ZERO:
                fprintf(stream, "%c0", signs[r.sign]);
                break;
        default:
                fprintf(stream, "[non-standard IEEE double]");
        }
}

void
ieee_printf_double(const double *x)
{
        ieee_fprintf_double(stdout, x);
}
