#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cml/math.h>

complex_t
complex(double real_part, double imaginary_part)
{
        complex_t z;

        z.re = real_part;
        z.im = imaginary_part;

        return z;
}


complex_t
complex_polar(double r, double theta)
{                               /* return z = r exp(i theta) */
        complex_t z;
        z = complex(r * real_cos(theta), r * real_sin(theta));
        return z;
}


complex_t
complex_nan()
{
        return complex(
                real_nan(),
                real_nan()
                );
}


complex_t
complex_inf()
{
        return complex(
                real_inf(),
                real_inf()
                );
}


complex_t
complex_ninf()
{
        return complex(
                real_ninf(),
                real_ninf()
                );
}


complex_t
complex_zero()
{
        return complex(0.0, 0.0);
}


complex_t
complex_clone(complex_t w)
{
        return complex(w.re, w.im);
}


char *
complex_as_string(complex_t z)
{
        char *x, *y, op[5], im[5];
        double im_value;

        im_value = z.im;

        x = (char*) real_as_string(z.re);
        y = (char*) real_as_string(z.im);

        strcpy(op, (im_value >= 0.0 ? " + " : " "));
        strcpy(im, "i");
        strcat(x, op);
        strcat(y, im);
        strcat(x, y);

        return x;
}
