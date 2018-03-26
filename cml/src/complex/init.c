#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cml/math.h>
#include <cml/complex.h>


cml_complex_t
cml_complex(double cml_part, double imaginary_part)
{
        cml_complex_t z;

        CML_SET_REAL(&z, cml_part);
        CML_SET_IMAG(&z, imaginary_part);

        return z;
}


cml_complex_t
cml_complex_polar(double r, double theta)
{                               /* return z = r exp(i theta) */
        cml_complex_t z;
        z = cml_complex(r * cml_cos(theta), r * cml_sin(theta));
        return z;
}


cml_complex_t
cml_complex_nan()
{
        return cml_complex(
                cml_nan(),
                cml_nan()
                );
}


cml_complex_t
cml_complex_inf()
{
        return cml_complex(
                cml_inf(),
                cml_inf()
                );
}


cml_complex_t
cml_complex_ninf()
{
        return cml_complex(
                cml_ninf(),
                cml_ninf()
                );
}


cml_complex_t
cml_complex_zero()
{
        return cml_complex(0.0, 0.0);
}


cml_complex_t
cml_complex_clone(cml_complex_t w)
{
        return cml_complex(CREAL(w), CIMAG(w));
}
