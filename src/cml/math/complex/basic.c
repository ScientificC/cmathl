#include <stdlib.h>
#include <cml.h>

real_t
complex_abs(complex_t z)
{
        /* Declaration of variables and structures */
        real_t n, a, b, w, h;

        /* Mathematical algorithm */
        n = 2.0;
        a = real_pow(creal(z), n);
        b = real_pow(cimag(z), n);
        w = real_add(a, b);
        h = real_sqrt(w);

        /* Return */
        return h;
}


/*
 * (a + bi) + (c + di) = (a+c) + (b+d)i
 *
 */

complex_t
complex_add(complex_t z, complex_t k)
{
        /* Declaration of variables and structures */
        complex_t w;
        real_t n, m;

        /* Mathematical algorithm */
        n = real_add(creal(z), creal(k));
        m = real_add(cimag(z), cimag(k));
        w = complex(n, m);

        /* Return */
        return w;
}


real_t
complex_arg(complex_t z)
{
        /* Declaration of variables and structures */
        real_t w;

        /* Mathematical algorithm */
        w = real_atan2(z.p[1], z.p[0]);

        /* Return */
        return w;
}

/*
 * Let z = a + bi, define the conjugate of z (w) as w = a - bi
 *
 */

complex_t
complex_conjugate(complex_t z)
{
        /* Declaration of variables and structures */
        complex_t r;

        /* Mathematical algorithm */
        r = complex(z.re, real_opposite(z.im));

        /* Return */
        return r;
}


complex_t
complex_div(complex_t z, complex_t k)
{
        /* Declaration of variables and structures */
        complex_t r, w;

        /* Mathematical algorithm */
        r = complex_inverse(k);
        w = complex_prod(z, r);

        /* Return */
        return w;
}


/*
 * It can be shown that, let z = a + bi a complex number, the multiplicative
 * inverse of z (w), with a⋅b ≠ 0, is W = conjugate(z) / abs(z)^2
 *
 */

complex_t
complex_inverse(complex_t z)
{
        /* Declaration of variables and structures */
        complex_t w, h;
        real_t a, b, m, n;


        /* Mathematical algorithm */
        w = complex_conjugate(z);
        a = complex_abs(z);
        b = real_pow(a, 2.0);
        n = real_div(w.p[0], b);
        m = real_div(w.p[1], b);

        h = complex(n, m);

        /* Return */
        return h;
}


/*
 * (a + bi) · (c + di) = (ac − bd) + (ad + bc)i
 *
 */

complex_t
complex_prod(complex_t z, complex_t k)
{
        /* Declaration of variables and structures */
        complex_t w;
        real_t a, b, c, d;

        /* Mathematical algorithm */
        a = z.p[0];
        b = z.p[1];
        c = k.p[0];
        d = k.p[1];

        w = complex(a*c - b*d, a*d + b*c);

        /* Return */
        return w;
}


complex_t
complex_scalar_prod(complex_t z, real_t k)
{
        /* Declaration of variables and structures */
        complex_t w;
        real_t x, y;

        /* Mathematical algorithm */
        x = real_prod(k, z.p[0]);
        y = real_prod(k, z.p[1]);
        w = complex(x, y);

        /* Return */
        return w;
}


complex_t
complex_sub(complex_t z, complex_t k)
{
        /* Declaration of variables and structures */
        complex_t h, w;
        real_t n, m;

        /* Mathematical algorithm */
        n = real_opposite(z.re);
        m = real_opposite(z.im);
        w = complex(n, m);
        h = complex_add(z, w);

        /* Return */
        return h;
}
