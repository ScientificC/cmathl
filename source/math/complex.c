#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/cml.h"

complex_t
complex_create(real real_part, real imaginary_part)
{
        complex_t self;

        init_complex(&self);
        self.real_part = real_new(real_part->real_value);
        self.imaginary_part = real_new(imaginary_part->real_value);

        return self;
}

complex
complex_new(real real_part, real imaginary_part)
{
        complex self = (complex) malloc(sizeof (complex_t));
        (*self) = complex_create(real_part, imaginary_part);

        return self;
}

void
complex_free(complex self)
{
        printf("%s\n", "You should free memory by using the function 'free' on the struct.");
}

real
complex_get_real(complex self)
{
        return self->real_part;
}

real
complex_get_imaginary(complex self)
{
        return self->imaginary_part;
}

void
complex_set_real(complex self, real x)
{
        self->real_part = x;
}

void
complex_set_imaginary(complex self, real x)
{
        self->imaginary_part = x;
}

real*
complex_get_parts(complex self)
{
        real* parts = malloc(sizeof(*parts));
        parts[0] = self->real(self);
        parts[1] = self->imaginary(self);
        return parts;
}

char *
complex_as_string(complex self)
{
        char *x, *y, op[5], im[5];
        double im_value;

        real* parts = self->parts(self);
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
init_complex(complex self)
{
        (*self) = (complex_t)
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
                .free = &complex_free
        };
}
