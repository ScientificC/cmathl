#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cml.h>

complex_t
_complex_create(real real_part, real imaginary_part)
{
        complex_t z;

        init_complex(&z);
        z.real_part = real_new(real_part->real_value);
        z.imaginary_part = real_new(imaginary_part->real_value);

        return z;
}

complex_t*
_complex_new(real real_part, real imaginary_part)
{
        complex_t* z = (complex_t*) malloc(sizeof (complex_t));
        (*z) = _complex_create(real_part, imaginary_part);

        return z;
}

complex_t*
_complex_clone(complex_t* w)
{
        complex_t* z = (complex_t*) malloc(sizeof (complex_t));
        (*z) = _complex_create(w->real_part, w->imaginary_part);

        return z;
}

void
_complex_free(complex_t* z)
{
        printf("%s\n", "You should free memory by using the function 'free' on the struct.");
}

real
complex_get_real(complex_t* z)
{
        return z->real_part;
}

real
complex_get_imaginary(complex_t* z)
{
        return z->imaginary_part;
}

void
complex_set_real(complex_t* z, real x)
{
        z->real_part = x;
}

void
complex_set_imaginary(complex_t* z, real x)
{
        z->imaginary_part = x;
}

real*
complex_get_parts(complex_t* z)
{
        real* parts = malloc(sizeof(*parts));
        parts[0] = z->real(z);
        parts[1] = z->imaginary(z);
        return parts;
}

char *
complex_as_string(complex_t* z)
{
        char *x, *y, op[5], im[5];
        double im_value;

        real* parts = z->parts(z);
        im_value = parts[1]->value(parts[1]);

        x = (char*) parts[0]->asString(parts[0]);
        y = (char*) parts[1]->asString(parts[1]);

        strcpy(op, (im_value >= 0.0 ? " + " : " "));
        strcpy(im, "i");
        strcat(x, op);
        strcat(y, im);
        strcat(x, y);

        free(parts);

        return x;
}

void
init_complex(complex_t* z)
{
        (*z) = (complex_t)
        {
                .real = &complex_get_real,
                .imaginary = &complex_get_imaginary,
                .setReal = &complex_set_real,
                .setImaginary = &complex_set_imaginary,
                .parts = &complex_get_parts,
                .asString = &complex_as_string,
                .add = &complex_add,
                .prod = &complex_prod,
                .scalar = &complex_scalar_prod,
                .sub = &complex_sub,
                .div = &complex_div,
                .abs = &complex_abs,
                .arg = &complex_arg,
                .inverse = &complex_inverse,
                .conjugate = &complex_conjugate,
                .exp = &complex_exp,
                .log = &complex_log,
                .logB = &complex_log_b,
                .sin = &complex_sin,
                .cos = &complex_cos,
                .tan = &complex_tan,
                .sec = &complex_sec,
                .csc = &complex_csc,
                .cot = &complex_cot,
                .sinh = &complex_sinh,
                .cosh = &complex_cosh,
                .tanh = &complex_tanh,
                .free = &_complex_free
        };
}
