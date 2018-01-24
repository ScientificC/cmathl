#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cml.h>

char *
real_as_string(real_t x)
{
        mfloat_t value = x;

        #ifndef PREDEF_STANDARD_C99
        char * string = (char*) malloc(80);
        sprintf(string, "%g", value);
        #else
        int size = snprintf(NULL, 0, "%G", value) + 1;
        char * string = (char*) malloc(size);
        snprintf(string, size, "%G", value);
        #endif

        return string;
}
