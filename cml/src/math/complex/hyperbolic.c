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
