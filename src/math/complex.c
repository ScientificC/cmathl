#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cml.h>

complex_t
_complex_create(mfloat_t real_part, mfloat_t imaginary_part)
{
        complex_t z;

        #ifndef CML_NO_FUNCTION_POINTER
        init_complex(&z);
        #endif

        z.real_part = real_part;
        z.imaginary_part = imaginary_part;

        return z;
}

complex_t*
_complex_new(mfloat_t real_part, mfloat_t imaginary_part)
{
        complex_t* z = (complex_t*) malloc(sizeof (complex_t));
        (*z) = _complex_create(real_part, imaginary_part);

        return z;
}

complex_t*
_complex_new_from_reals(real a, real b)
{
        return _complex_new(real_value(a), real_value(b));
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
        return real_new(z->real_part);
}

real
complex_get_imaginary(complex_t* z)
{
        return real_new(z->imaginary_part);
}

void
complex_set_real(complex_t* z, mfloat_t x)
{
        z->real_part = x;
}

void
complex_set_imaginary(complex_t* z, mfloat_t x)
{
        z->imaginary_part = x;
}

real*
complex_get_parts(complex_t* z)
{
        real* parts = malloc(sizeof(*parts));

        parts[0] = complex_get_real(z);
        parts[1] = complex_get_imaginary(z);

        return parts;
}

char *
complex_as_string(complex_t* z)
{
        char *x, *y, op[5], im[5];
        mfloat_t im_value;

        real* parts = complex_get_parts(z);
        im_value = real_value(parts[1]);

        x = (char*) real_as_string(parts[0]);
        y = (char*) real_as_string(parts[1]);

        strcpy(op, (im_value >= 0.0 ? " + " : " "));
        strcpy(im, "i");
        strcat(x, op);
        strcat(y, im);
        strcat(x, y);

        free(parts);

        return x;
}

#ifndef CML_NO_FUNCTION_POINTER
void
init_complex(complex_t* z)
{
        (*z) = (complex_t)
        {
                .getReal = &complex_get_real,
                .getImaginary = &complex_get_imaginary,
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
#endif
