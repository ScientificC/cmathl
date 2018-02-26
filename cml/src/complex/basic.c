#include <stdlib.h>
#include <cml/math.h>
#include <cml/complex.h>

double
cml_complex_abs(cml_complex_t z)
{
        /* Declaration of variables and structures */
        double n, a, b, w, h;

        /* Mathematical algorithm */
        n = 2.0;
        a = cml_pow(z.re, n);
        b = cml_pow(z.im, n);
        w = cml_add(a, b);
        h = cml_sqrt(w);

        /* Return */
        return h;
}


double
cml_complex_logabs(cml_complex_t z)
{                               /* return log|z| */
        double xabs = cml_abs(z.re);
        double yabs = cml_abs(z.im);
        double max, u;

        if (xabs >= yabs)
        {
                max = xabs;
                u = yabs / xabs;
        }
        else
        {
                max = yabs;
                u = xabs / yabs;
        }

        /* Handle underflow when u is close to 0 */
        return cml_log(max) + 0.5 * cml_log1p(u*u);
}


/*
 * (a + bi) + (c + di) = (a+c) + (b+d)i
 *
 */

cml_complex_t
cml_complex_add(cml_complex_t z, cml_complex_t k)
{
        /* Declaration of variables and structures */
        cml_complex_t w;
        double n, m;

        /* Mathematical algorithm */
        n = cml_add(z.re, k.re);
        m = cml_add(z.im, k.im);
        w = complex(n, m);

        /* Return */
        return w;
}


double
cml_complex_arg(cml_complex_t z)
{
        /* Declaration of variables and structures */
        double w;

        /* Mathematical algorithm */
        w = cml_atan2(z.p[1], z.p[0]);

        /* Return */
        return w;
}

/*
 * Let z = a + bi, define the conjugate of z (w) as w = a - bi
 *
 */

cml_complex_t
cml_complex_conjugate(cml_complex_t z)
{
        /* Declaration of variables and structures */
        cml_complex_t r;

        /* Mathematical algorithm */
        r = complex(z.re, cml_opposite(z.im));

        /* Return */
        return r;
}


cml_complex_t
cml_complex_div(cml_complex_t z, cml_complex_t k)
{
        /* Declaration of variables and structures */
        cml_complex_t r, w;

        /* Mathematical algorithm */
        r = cml_complex_inverse(k);
        w = cml_complex_mul(z, r);

        /* Return */
        return w;
}


/*
 * It can be shown that, let z = a + bi a complex number, the multiplicative
 * inverse of z (w), with a⋅b ≠ 0, is W = conjugate(z) / abs(z)^2
 *
 */

cml_complex_t
cml_complex_inverse(cml_complex_t z)
{
        /* Declaration of variables and structures */
        cml_complex_t w, h;
        double a, b, m, n;


        /* Mathematical algorithm */
        w = cml_complex_conjugate(z);
        a = cml_complex_abs(z);
        b = a*a;
        n = cml_div(w.p[0], b);
        m = cml_div(w.p[1], b);

        h = complex(n, m);

        /* Return */
        return h;
}


/*
 * (a + bi) · (c + di) = (ac − bd) + (ad + bc)i
 *
 */

cml_complex_t
cml_complex_mul(cml_complex_t z, cml_complex_t k)
{
        /* Declaration of variables and structures */
        cml_complex_t w;
        double a, b, c, d;

        /* Mathematical algorithm */
        a = z.p[0];
        b = z.p[1];
        c = k.p[0];
        d = k.p[1];

        w = complex(a*c - b*d, a*d + b*c);

        /* Return */
        return w;
}


cml_complex_t
cml_complex_scalar_mul(cml_complex_t z, double k)
{
        /* Declaration of variables and structures */
        cml_complex_t w;
        double x, y;

        /* Mathematical algorithm */
        x = cml_mul(k, z.p[0]);
        y = cml_mul(k, z.p[1]);
        w = complex(x, y);

        /* Return */
        return w;
}


cml_complex_t
cml_complex_sub(cml_complex_t z, cml_complex_t k)
{
        /* Declaration of variables and structures */
        cml_complex_t h, w;
        double n, m;

        /* Mathematical algorithm */
        n = cml_opposite(k.re);
        m = cml_opposite(k.im);
        w = complex(n, m);
        h = cml_complex_add(z, w);

        /* Return */
        return h;
}


cml_complex_t
cml_complex_add_real(cml_complex_t a, double x)
{                               /* z=a+x */
        cml_complex_t z;
        z = complex(a.re + x, a.im);
        return z;
}


cml_complex_t
cml_complex_add_imag(cml_complex_t a, double y)
{                               /* z=a+iy */
        cml_complex_t z;
        z = complex(a.re, a.im + y);
        return z;
}

cml_complex_t
cml_complex_sub_real(cml_complex_t a, double x)
{                               /* z=a-x */
        cml_complex_t z;
        z = complex(a.re - x, a.im);
        return z;
}


cml_complex_t
cml_complex_sub_imag(cml_complex_t a, double y)
{                               /* z=a-iy */
        cml_complex_t z;
        z = complex(a.re, a.im - y);
        return z;
}

cml_complex_t
cml_complex_mul_real(cml_complex_t a, double x)
{                               /* z=a*x */
        cml_complex_t z;
        z = complex(x * a.re, x * a.im);
        return z;
}


cml_complex_t
cml_complex_mul_imag(cml_complex_t a, double y)
{                               /* z=a*iy */
        cml_complex_t z;
        z = complex(-y * a.im, y * a.re);
        return z;
}

cml_complex_t
cml_complex_div_real(cml_complex_t a, double x)
{                               /* z=a/x */
        cml_complex_t z;
        z = complex(a.re / x, a.im / x);
        return z;
}


cml_complex_t
cml_complex_div_imag(cml_complex_t a, double y)
{                               /* z=a/(iy) */
        cml_complex_t z;
        z = complex(a.im / y,  -a.re / y);
        return z;
}
