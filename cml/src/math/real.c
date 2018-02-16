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
        long double value = (long double) x;

        #ifndef PREDEF_STANDARD_C99
        char * string = (char*) malloc(80);
        sprintf(string, "%Lg", value);
        #else
        int size = snprintf(NULL, 0, "%Lg", value) + 1;
        char * string = (char*) malloc(size);
        snprintf(string, size, "%Lg", value);
        #endif

        return string;
}
