#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cml/math.h>

double
cml_nan()
{
        return (double) NAN;
}


double
cml_inf()
{
        return (double) POSINF;
}


double
cml_ninf()
{
        return (double) NEGINF;
}
