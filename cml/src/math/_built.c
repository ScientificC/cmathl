#include <stdlib.h>
#include <cml/math.h>

__CML_EXTERN_INLINE double
cml_nan()
{
        return (double) CML_NAN;
}


__CML_EXTERN_INLINE double
cml_inf()
{
        return (double) CML_POSINF;
}


__CML_EXTERN_INLINE double
cml_ninf()
{
        return (double) CML_NEGINF;
}
