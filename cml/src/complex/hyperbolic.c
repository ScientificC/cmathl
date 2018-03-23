#include <stdlib.h>
#include <cml/math.h>
#include <cml/complex.h>


/*
 * cosh(Z) = (cos(b) * ((e^a + e^-a) / 2) + (sin(b) * (e^a - e^-a) / 2))i
 * cosh(Z) = (cos(b) * cosh(a)) + (sin(b) * sinh(a))i
 *
 * @param complex z
 *
 * @return complex cosh(z)
 *
 */

cml_complex_t
cml_complex_cosh(cml_complex_t z)
{
        cml_complex_t w;
        double k, h, a, b, n, m;

        k = cml_cos(CIMAG(z));
        h = cml_sin(CIMAG(z));
        a = cml_cosh(CREAL(z));
        b = cml_sinh(CREAL(z));

        n = k * a;
        m = h * b;

        w = complex(n, m);

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

cml_complex_t
cml_complex_sinh(cml_complex_t z)
{
        cml_complex_t w;
        double k, h, a, b, n, m;

        k = cml_cos(CIMAG(z));
        h = cml_sin(CIMAG(z));
        a = cml_sinh(CREAL(z));
        b = cml_cosh(CREAL(z));

        n = k * a;
        m = h * b;

        w = complex(n, m);

        return w;
}


cml_complex_t
cml_complex_tanh(cml_complex_t z)
{
        cml_complex_t c = cml_complex_cosh(z);
        double a = cml_complex_abs(c);
        if (!cml_isnull(a)) {
                return cml_complex_nan();
        }

        cml_complex_t s, w;

        s = cml_complex_sinh(z);
        w = cml_complex_div(s, c);

        return w;
}


cml_complex_t
cml_complex_sech(cml_complex_t a)
{                               /* z = sech(a) */
        cml_complex_t z = cml_complex_cosh(a);
        return cml_complex_inverse(z);
}


cml_complex_t
cml_complex_csch(cml_complex_t a)
{                               /* z = csch(a) */
        cml_complex_t z = cml_complex_sinh(a);
        return cml_complex_inverse(z);
}


cml_complex_t
cml_complex_coth(cml_complex_t a)
{                               /* z = coth(a) */
        cml_complex_t z = cml_complex_tanh(a);
        return cml_complex_inverse(z);
}


cml_complex_t
cml_complex_asinh(cml_complex_t a)
{                               /* z = asinh(a) */
        cml_complex_t z = cml_complex_mul_imag(a, 1.0);
        z = cml_complex_asin(z);
        z = cml_complex_mul_imag(z, -1.0);
        return z;
}


cml_complex_t
cml_complex_acosh(cml_complex_t a)
{                               /* z = acosh(a) */
        cml_complex_t z = cml_complex_acos(a);
        z = cml_complex_mul_imag(z, CIMAG(z) > 0 ? -1.0 : 1.0);
        return z;
}


cml_complex_t
cml_complex_acosh_real(double a)
{                               /* z = acosh(a) */
        cml_complex_t z;

        if (a >= 1)
        {
                z = complex(cml_acosh(a), 0);
        }
        else
        {
                if (a >= -1.0)
                {
                        z = complex(0, cml_acos(a));
                }
                else
                {
                        z = complex(cml_acosh(-a), M_PI);
                }
        }

        return z;
}


cml_complex_t
cml_complex_atanh(cml_complex_t a)
{                               /* z = atanh(a) */
        if (CIMAG(a) == 0.0)
        {
                return cml_complex_atanh_real(CREAL(a));
        }
        else
        {
                cml_complex_t z = cml_complex_mul_imag(a, 1.0);
                z = cml_complex_atan(z);
                z = cml_complex_mul_imag(z, -1.0);
                return z;
        }
}


cml_complex_t
cml_complex_atanh_real(double a)
{                               /* z = atanh(a) */
        cml_complex_t z;

        if (a > -1.0 && a < 1.0)
        {
                z = complex(cml_atanh(a), 0);
        }
        else
        {
                z = complex(cml_atanh(1 / a), (a < 0) ? M_PI_2 : -M_PI_2);
        }

        return z;
}


cml_complex_t
cml_complex_asech(cml_complex_t a)
{                               /* z = asech(a); */
        cml_complex_t t = cml_complex_inverse(a);
        return cml_complex_acosh(t);
}


cml_complex_t
cml_complex_acsch(cml_complex_t a)
{                               /* z = acsch(a) */
        cml_complex_t t = cml_complex_inverse(a);
        return cml_complex_asinh(t);
}


cml_complex_t
cml_complex_acoth(cml_complex_t a)
{                               /* z = acoth(a) */
        cml_complex_t t = cml_complex_inverse(a);
        return cml_complex_atanh(t);
}
