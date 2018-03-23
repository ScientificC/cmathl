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
        a = cml_pow(CREAL(z), n);
        b = cml_pow(CIMAG(z), n);
        w = a + b;
        h = cml_sqrt(w);

        /* Return */
        return h;
}


double
cml_complex_logabs(cml_complex_t z)
{                               /* return log|z| */
        double xabs = cml_abs(CREAL(z));
        double yabs = cml_abs(CIMAG(z));
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
        n = CREAL(z) + CREAL(k);
        m = CIMAG(z) + CIMAG(k);
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
        w = cml_atan2(CIMAG(z), CREAL(z));

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
        r = complex(CREAL(z), cml_opposite(CIMAG(z)));

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
        n = CREAL(w) / b;
        m = CIMAG(w) / b;

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
        a = CREAL(z);
        b = CIMAG(z);
        c = CREAL(k);
        d = CIMAG(k);

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
        x = k * CREAL(z);
        y = k * CIMAG(z);
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
        n = cml_opposite(CREAL(k));
        m = cml_opposite(CIMAG(k));
        w = complex(n, m);
        h = cml_complex_add(z, w);

        /* Return */
        return h;
}


cml_complex_t
cml_complex_add_real(cml_complex_t a, double x)
{                               /* z=a+x */
        cml_complex_t z;
        z = complex(CREAL(a) + x, CIMAG(a));
        return z;
}


cml_complex_t
cml_complex_add_imag(cml_complex_t a, double y)
{                               /* z=a+iy */
        cml_complex_t z;
        z = complex(CREAL(a), CIMAG(a) + y);
        return z;
}

cml_complex_t
cml_complex_sub_real(cml_complex_t a, double x)
{                               /* z=a-x */
        cml_complex_t z;
        z = complex(CREAL(a) - x, CIMAG(a));
        return z;
}


cml_complex_t
cml_complex_sub_imag(cml_complex_t a, double y)
{                               /* z=a-iy */
        cml_complex_t z;
        z = complex(CREAL(a), CIMAG(a) - y);
        return z;
}

cml_complex_t
cml_complex_mul_real(cml_complex_t a, double x)
{                               /* z=a*x */
        cml_complex_t z;
        z = complex(x * CREAL(a), x * CIMAG(a));
        return z;
}


cml_complex_t
cml_complex_mul_imag(cml_complex_t a, double y)
{                               /* z=a*iy */
        cml_complex_t z;
        z = complex(-y * CIMAG(a), y * CREAL(a));
        return z;
}

cml_complex_t
cml_complex_div_real(cml_complex_t a, double x)
{                               /* z=a/x */
        cml_complex_t z;
        z = complex(CREAL(a) / x, CIMAG(a) / x);
        return z;
}


cml_complex_t
cml_complex_div_imag(cml_complex_t a, double y)
{                               /* z=a/(iy) */
        cml_complex_t z;
        z = complex(CIMAG(a) / y,  -CREAL(a) / y);
        return z;
}
