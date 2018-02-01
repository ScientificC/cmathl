#include <stdlib.h>
#include <cml.h>

/*
 * cos(Z) = (cos(a) * ((e^b - e^-b) / 2) + (sin(a) * (e^b + e^-b) / 2))i
 * cos(Z) = (cos(a) * sinh(b)) + (sin(a) * cosh(b))i
 *
 * @param complex z
 *
 * @return complex cos(z)
 *
 */

complex_t
complex_cos(complex_t z)
{
        /* Declaration of variables and structures */
        complex_t w;
        real_t k, h, a, b, n, m;

        /* Mathematical algorithm */
        k = real_cos(z.p[0]);
        h = real_sin(z.p[0]);
        a = real_sinh(z.p[1]);
        b = real_cosh(z.p[1]);

        n = real_prod(k, a);
        m = real_prod(h, b);

        w = complex(n, m);

        /* Return */
        return w;
}


complex_t
complex_cot(complex_t z)
{
        /* Domain check */
        complex_t s = complex_sin(z);
        real_t a = complex_abs(s);
        if (!real_isnull(a)) {
                return complex_nan();
        }

        /* Declaration of variables and structures */
        complex_t c, w;

        /* Mathematical algorithm */
        c = complex_cos(z);
        w = complex_div(c, s);

        /* Return */
        return w;
}


complex_t
complex_csc(complex_t z)
{
        /* Domain check */
        complex_t s = complex_sin(z);
        real_t a = complex_abs(s);
        if (!real_isnull(a)) {
                return complex_nan();
        }

        /* Declaration of variables and structures */
        complex_t w;

        /* Mathematical algorithm */
        w = complex_inverse(s);

        /* Return */
        return w;
}


complex_t
complex_sec(complex_t z)
{
        /* Domain check */
        complex_t c = complex_cos(z);
        real_t a = complex_abs(c);
        if (!real_isnull(a)) {
                return complex_nan();
        }

        /* Declaration of variables and structures */
        complex_t w;

        /* Mathematical algorithm */
        w = complex_inverse(c);

        /* Return */
        return w;
}


/*
 * sin(Z) = (sin(a) * ((e^b + e^-b) / 2) + (Cos(a) * (e^b - e^-b) / 2))i
 * sin(Z) = (sin(a) * cosh(b)) + (cos(a) * sinh(b))i
 *
 * @param complex z
 *
 * @return complex sin(z)
 *
 */

complex_t
complex_sin(complex_t z)
{
        /* Declaration of variables and structures */
        complex_t w;
        real_t k, h, a, b, n, m;

        /* Mathematical algorithm */
        k = real_sin(z.re);
        h = real_cos(z.re);
        a = real_cosh(z.im);
        b = real_sinh(z.im);

        n = real_prod(k, a);
        m = real_prod(h, b);

        w = complex(n, m);

        /* Return */
        return w;
}


complex_t
complex_tan(complex_t z)
{
        /* Domain check */
        complex_t c = complex_cos(z);
        real_t a = complex_abs(c);
        if (!real_isnull(a)) {
                return complex_nan();
        }

        /* Declaration of variables and structures */
        complex_t s, w;

        /* Mathematical algorithm */
        s = complex_sin(z);
        w = complex_div(s, c);

        /* Return */
        return w;
}
