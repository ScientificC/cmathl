#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cml/math.h>

double
cml_nan()
{
        return (double) CML_NAN;
}


double
cml_inf()
{
        return (double) CML_POSINF;
}


double
cml_ninf()
{
        return (double) CML_NEGINF;
}
