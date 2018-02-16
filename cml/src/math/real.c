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
        #ifndef PREDEF_STANDARD_C99
        char * string = (char*) malloc(80);
        #ifndef CML_NO_LONG_DOUBLE_MATH
        sprintf(string, "%Lg", x);
        #else
        sprintf(string, "%g", x);
        #endif
        #else
        #ifndef CML_NO_LONG_DOUBLE_MATH
        int size = snprintf(NULL, 0, "%Lg", x) + 1;
        #else
        int size = snprintf(NULL, 0, "%g", x) + 1;
        #endif
        char * string = (char*) malloc(size);
        #ifndef CML_NO_LONG_DOUBLE_MATH
        snprintf(string, size, "%Lg", x);
        #else
        snprintf(string, size, "%g", x);
        #endif
        #endif

        return string;
}
