#include <stdlib.h>
#include <cml.h>

/*
 * cosh(Z) = (cos(b) * ((e^a + e^-a) / 2) + (sin(b) * (e^a - e^-a) / 2))i
 * cosh(Z) = (cos(b) * cosh(a)) + (sin(b) * sinh(a))i
 *
 * @param complex z
 *
 * @return complex cosh(z)
 *
 */

complex_t
complex_cosh(complex_t z)
{
        /* Declaration of variables and structures */
        complex_t w;
        real_t k, h, a, b, n, m;

        /* Mathematical algorithm */
        k = real_cos(z.p[1]);
        h = real_sin(z.p[1]);
        a = real_cosh(z.p[0]);
        b = real_sinh(z.p[0]);

        n = real_mul(k, a);
        m = real_mul(h, b);

        w = complex(n, m);

        /* Return */
        return w;
}


/*
 * sinh(Z) = (cos(b) * ((e^a - e^-a) / 2) + (sin(b) * (e^a + e^-a) / 2))i
 * sinh(Z) = (cos(b) * cosh(a)) + (sin(b) * sinh(a))i
 *
 * @param complex z
 *
 * @return complex sinh(z)
 *
 */

complex_t
complex_sinh(complex_t z)
{
        /* Declaration of variables and structures */
        complex_t w;
        real_t k, h, a, b, n, m;

        /* Mathematical algorithm */
        k = real_cos(z.im);
        h = real_sin(z.im);
        a = real_sinh(z.re);
        b = real_cosh(z.re);

        n = real_mul(k, a);
        m = real_mul(h, b);

        w = complex(n, m);

        /* Return */
        return w;
}


complex_t
complex_tanh(complex_t z)
{
        /* Domain check */
        complex_t c = complex_cosh(z);
        real_t a = complex_abs(c);
        if (!real_isnull(a)) {
                return complex_nan();
        }

        /* Declaration of variables and structures */
        complex_t s, w;

        /* Mathematical algorithm */
        s = complex_sinh(z);
        w = complex_div(s, c);

        /* Return */
        return w;
}


complex_t
complex_sech(complex_t a)
{                               /* z = sech(a) */
        complex_t z = complex_cosh(a);
        return complex_inverse(z);
}


complex_t
complex_csch(complex_t a)
{                               /* z = csch(a) */
        complex_t z = complex_sinh(a);
        return complex_inverse(z);
}


complex_t
complex_coth(complex_t a)
{                               /* z = coth(a) */
        complex_t z = complex_tanh(a);
        return complex_inverse(z);
}


complex_t
complex_asinh(complex_t a)
{                               /* z = asinh(a) */
        complex_t z = complex_mul_imag(a, 1.0);
        z = complex_asin(z);
        z = complex_mul_imag(z, -1.0);
        return z;
}


complex_t
complex_acosh(complex_t a)
{                               /* z = acosh(a) */
        complex_t z = complex_acos(a);
        z = complex_mul_imag(z, z.im > 0 ? -1.0 : 1.0);
        return z;
}


complex_t
complex_acosh_real(real_t a)
{                               /* z = acosh(a) */
        complex_t z;

        if (a >= 1)
        {
                z = complex(real_acosh(a), 0);
        }
        else
        {
                if (a >= -1.0)
                {
                        z = complex(0, real_acos(a));
                }
                else
                {
                        z = complex(real_acosh(-a), PI);
                }
        }

        return z;
}


complex_t
complex_atanh(complex_t a)
{                               /* z = atanh(a) */
        if (a.im == 0.0)
        {
                return complex_atanh_real(a.re);
        }
        else
        {
                complex_t z = complex_mul_imag(a, 1.0);
                z = complex_atan(z);
                z = complex_mul_imag(z, -1.0);
                return z;
        }
}


complex_t
complex_atanh_real(real_t a)
{                               /* z = atanh(a) */
        complex_t z;

        if (a > -1.0 && a < 1.0)
        {
                z = complex(real_atanh(a), 0);
        }
        else
        {
                z = complex(real_atanh(1 / a), (a < 0) ? HALFPI : -HALFPI);
        }

        return z;
}


complex_t
complex_asech(complex_t a)
{                               /* z = asech(a); */
        complex_t t = complex_inverse(a);
        return complex_acosh(t);
}


complex_t
complex_acsch(complex_t a)
{                               /* z = acsch(a) */
        complex_t t = complex_inverse(a);
        return complex_asinh(t);
}


complex_t
complex_acoth(complex_t a)
{                               /* z = acoth(a) */
        complex_t t = complex_inverse(a);
        return complex_atanh(t);
}
