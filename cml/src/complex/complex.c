#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cml/math.h>
#include <cml/complex.h>


cml_complex_t
complex(double cml_part, double imaginary_part)
{
        cml_complex_t z;

        z.re = cml_part;
        z.im = imaginary_part;

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
        return complex(w.re, w.im);
}


char *
cml_complex_as_string(cml_complex_t z)
{
        char *x, *y, op[5], im[5];
        double im_value;

        im_value = z.im;

        x = (char*) cml_as_string(z.re);
        y = (char*) cml_as_string(z.im);

        strcpy(op, (im_value >= 0.0 ? " + " : " "));
        strcpy(im, "i");
        strcat(x, op);
        strcat(y, im);
        strcat(x, y);

        return x;
}
