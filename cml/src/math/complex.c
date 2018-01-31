#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cml.h>

complex_t
complex(real_t real_part, real_t imaginary_part)
{
        complex_t z;

        z.re = real_part;
        z.im = imaginary_part;

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
complex_clone(complex_t w)
{
        return complex(w.re, w.im);
}


char *
complex_as_string(complex_t z)
{
        char *x, *y, op[5], im[5];
        real_t im_value;

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
