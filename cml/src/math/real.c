#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cml.h>

real_t
real_nan()
{
        return (real_t) NAN;
}


real_t
real_inf()
{
        return (real_t) INF;
}


real_t
real_ninf()
{
        return (real_t) NINF;
}


char *
real_as_string(real_t x)
{
        mfloat_t value = x;

        #ifndef PREDEF_STANDARD_C99
        char * string = (char*) malloc(80);
        #ifndef CML_NO_LONG_DOUBLE_MATH
        sprintf(string, "%Lg", value);
        #else
        sprintf(string, "%g", value);
        #endif
        #else
        #ifndef CML_NO_LONG_DOUBLE_MATH
        int size = snprintf(NULL, 0, "%Lg", value) + 1;
        #else
        int size = snprintf(NULL, 0, "%g", value) + 1;
        #endif
        char * string = (char*) malloc(size);
        #ifndef CML_NO_LONG_DOUBLE_MATH
        snprintf(string, size, "%Lg", value);
        #else
        snprintf(string, size, "%g", value);
        #endif
        #endif

        return string;
}
