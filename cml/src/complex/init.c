#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cml/math.h>
#include <cml/complex.h>


cml_complex_t
complex(double cml_part, double imaginary_part)
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
        z = complex(r * cml_cos(theta), r * cml_sin(theta));
        return z;
}


cml_complex_t
cml_complex_nan()
{
        return complex(
                cml_nan(),
                cml_nan()
                );
}


cml_complex_t
cml_complex_inf()
{
        return complex(
                cml_inf(),
                cml_inf()
                );
}


cml_complex_t
cml_complex_ninf()
{
        return complex(
                cml_ninf(),
                cml_ninf()
                );
}


cml_complex_t
cml_complex_zero()
{
        return complex(0.0, 0.0);
}


cml_complex_t
cml_complex_clone(cml_complex_t w)
{
        return complex(CREAL(w), CIMAG(w));
}
