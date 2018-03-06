#include <stdlib.h>
#include <cml/math.h>
#include <cml/complex.h>


/*
 * cos(Z) = (cos(a) * ((e^b - e^-b) / 2) + (sin(a) * (e^b + e^-b) / 2))i
 * cos(Z) = (cos(a) * sinh(b)) + (sin(a) * cosh(b))i
 *
 * @param cml_complex_t z
 *
 * @return cml_complex_t cos(z)
 *
 */

cml_complex_t
cml_complex_cos(cml_complex_t z)
{
        double k = cml_cos(CREAL(z));

        if (cml_isnull(CIMAG(z)))
        {
                return complex(k, 0.0);
        }

        cml_complex_t w;
        double h, a, b, n, m;

        h = cml_sin(CREAL(z));
        a = cml_sinh(CIMAG(z));
        b = cml_cosh(CIMAG(z));
        n = cml_mul(k, a);
        m = cml_mul(h, b);

        w = complex(n, m);

        return w;
}


cml_complex_t
cml_complex_cot(cml_complex_t z)
{
        cml_complex_t s = cml_complex_sin(z);
        double a = cml_complex_abs(s);
        if (!cml_isnull(a))
        {
                return cml_complex_nan();
        }

        cml_complex_t c, w;

        c = cml_complex_cos(z);
        w = cml_complex_div(c, s);

        return w;
}


cml_complex_t
cml_complex_csc(cml_complex_t z)
{
        cml_complex_t s = cml_complex_sin(z);
        double a = cml_complex_abs(s);
        if (!cml_isnull(a))
        {
                return cml_complex_nan();
        }

        cml_complex_t w;

        w = cml_complex_inverse(s);

        return w;
}


cml_complex_t
cml_complex_sec(cml_complex_t z)
{
        cml_complex_t c = cml_complex_cos(z);
        double a = cml_complex_abs(c);
        if (!cml_isnull(a))
        {
                return cml_complex_nan();
        }

        cml_complex_t w;

        w = cml_complex_inverse(c);

        return w;
}


/*
 * sin(Z) = (sin(a) * ((e^b + e^-b) / 2) + (Cos(a) * (e^b - e^-b) / 2))i
 * sin(Z) = (sin(a) * cosh(b)) + (cos(a) * sinh(b))i
 *
 * @param cml_complex_t z
 *
 * @return cml_complex_t sin(z)
 *
 */

cml_complex_t
cml_complex_sin(cml_complex_t z)
{
        double k = cml_sin(CREAL(z));

        if (cml_isnull(CIMAG(z)))
        {
                return complex(k, 0.0);
        }

        cml_complex_t w;
        double h, a, b, n, m;

        h = cml_cos(CREAL(z));
        a = cml_cosh(CIMAG(z));
        b = cml_sinh(CIMAG(z));

        n = cml_mul(k, a);
        m = cml_mul(h, b);

        w = complex(n, m);

        return w;
}


cml_complex_t
cml_complex_tan(cml_complex_t a)
{                               /* z = tan(a) */
        cml_complex_t z;

        double R = CREAL(a), I = CIMAG(a);
        double D = cml_pow(cml_cos(R), 2.0) + cml_pow(cml_sinh(I), 2.0);

        if (cml_abs(I) < 1)
        {
                z = complex(0.5 * cml_sin(2 * R) / D, 0.5 * cml_sinh(2 * I) / D);
        }
        else
        {
                double F = 1 + cml_pow(cml_cos(R)/cml_sinh(I), 2.0);

                z = complex(0.5 * cml_sin(2 * R) / D, 1 / (doubleanh(I) * F));
        }

        return z;
}


cml_complex_t
cml_complex_asin(cml_complex_t a)
{                               /* z = asin(a) */
        double R = CREAL(a), I = CIMAG(a);
        cml_complex_t z;

        if (cml_isnull(I))
        {
                z = cml_complex_asin_real(R);
        }
        else
        {
                double x = cml_abs(R), y = cml_abs(I);
                double r = cml_hypot(x + 1, y), s = cml_hypot(x - 1, y);
                double A = 0.5 * (r + s);
                double B = x / A;
                double y2 = y * y;

                double real, imag;

                const double A_crossover = 1.5, B_crossover = 0.6417;

                if (B <= B_crossover)
                {
                        real = cml_asin(B);
                }
                else
                {
                        if (x <= 1)
                        {
                                double D = 0.5 * (A + x) * (y2 / (r + x + 1) + (s + (1 - x)));
                                real = cml_atan(x / cml_sqrt(D));
                        }
                        else
                        {
                                double Apx = A + x;
                                double D = 0.5 * (Apx / (r + x + 1) + Apx / (s + (x - 1)));
                                real = cml_atan(x / (y * cml_sqrt(D)));
                        }
                }

                if (A <= A_crossover)
                {
                        double Am1;

                        if (x < 1)
                        {
                                Am1 = 0.5 * (y2 / (r + (x + 1)) + y2 / (s + (1 - x)));
                        }
                        else
                        {
                                Am1 = 0.5 * (y2 / (r + (x + 1)) + (s + (x - 1)));
                        }

                        imag = cml_log1p(Am1 + cml_sqrt(Am1 * (A + 1)));
                }
                else
                {
                        imag = cml_log(A + cml_sqrt(A * A - 1));
                }

                z = complex((R >= 0) ? real : -real, (I >= 0) ? imag : -imag);
        }

        return z;
}

cml_complex_t
cml_complex_asin_real(double a)
{                               /* z = asin(a) */
        cml_complex_t z;

        if (cml_abs(a) <= 1.0)
        {
                z = complex(cml_asin(a), 0.0);
        }
        else
        {
                if (a < 0.0)
                {
                        z = complex(-M_PI_2, cml_acosh(-a));
                }
                else
                {
                        z = complex(M_PI_2, -cml_acosh(a));
                }
        }

        return z;
}

cml_complex_t
cml_complex_acos(cml_complex_t a)
{                               /* z = acos(a) */
        double R = CREAL(a), I = CIMAG(a);
        cml_complex_t z;

        if (I == 0)
        {
                z = cml_complex_acos_real(R);
        }
        else
        {
                double x = cml_abs(R), y = cml_abs(I);
                double r = cml_hypot(x + 1, y), s = cml_hypot(x - 1, y);
                double A = 0.5 * (r + s);
                double B = x / A;
                double y2 = y * y;

                double real, imag;

                const double A_crossover = 1.5, B_crossover = 0.6417;

                if (B <= B_crossover)
                {
                        real = cml_acos(B);
                }
                else
                {
                        if (x <= 1)
                        {
                                double D = 0.5 * (A + x) * (y2 / (r + x + 1) + (s + (1 - x)));
                                real = cml_atan(cml_sqrt(D) / x);
                        }
                        else
                        {
                                double Apx = A + x;
                                double D = 0.5 * (Apx / (r + x + 1) + Apx / (s + (x - 1)));
                                real = cml_atan((y * cml_sqrt(D)) / x);
                        }
                }

                if (A <= A_crossover)
                {
                        double Am1;

                        if (x < 1)
                        {
                                Am1 = 0.5 * (y2 / (r + (x + 1)) + y2 / (s + (1 - x)));
                        }
                        else
                        {
                                Am1 = 0.5 * (y2 / (r + (x + 1)) + (s + (x - 1)));
                        }

                        imag = cml_log1p(Am1 + cml_sqrt(Am1 * (A + 1)));
                }
                else
                {
                        imag = cml_log(A + cml_sqrt(A * A - 1));
                }

                z = complex((R >= 0) ? real : M_PI - real, (I >= 0) ? -imag : imag);
        }

        return z;
}

cml_complex_t
cml_complex_acos_real(double a)
{                               /* z = acos(a) */
        cml_complex_t z;

        if (cml_abs(a) <= 1.0)
        {
                z = complex(cml_acos(a), 0);
        }
        else
        {
                if (a < 0.0)
                {
                        z = complex(M_PI, -cml_acosh(-a));
                }
                else
                {
                        z = complex(0, cml_acosh(a));
                }
        }

        return z;
}

cml_complex_t
cml_complex_atan(cml_complex_t a)
{                               /* z = atan(a) */
        double R = CREAL(a), I = CIMAG(a);
        cml_complex_t z;

        if (cml_isnull(I))
        {
                z = complex(cml_atan(R), 0);
        }
        else
        {
                /* FIXME: This is a naive implementation which does not fully
                   take into account cancellation errors, overflow, underflow
                   etc.  It would benefit from the Hull et al treatment. */

                double r = cml_hypot(R, I);

                double imag;

                double u = 2 * I / (1 + r * r);

                /* FIXME: the following cross-over should be optimized but 0.1
                   seems to work ok */

                if (cml_abs(u) < 0.1)
                {
                        imag = 0.25 * (cml_log1p(u) - cml_log1p(-u));
                }
                else
                {
                        double A = cml_hypot(R, I + 1);
                        double B = cml_hypot(R, I - 1);
                        imag = 0.5 * cml_log(A / B);
                }

                if (cml_isnull(R))
                {
                        if (I > 1)
                        {
                                z = complex(M_PI_2, imag);
                        } else if (I < -1)
                        {
                                z = complex(-M_PI_2, imag);
                        }
                        else
                        {
                                z = complex(0, imag);
                        }
                }
                else
                {
                        z = complex(0.5 * cml_atan2(2 * R, ((1 + r) * (1 - r))), imag);
                }
        }

        return z;
}

cml_complex_t
cml_complex_asec(cml_complex_t a)
{                               /* z = asec(a) */
        cml_complex_t z = cml_complex_inverse(a);
        return cml_complex_acos(z);
}

cml_complex_t
cml_complex_asec_real(double a)
{                               /* z = asec(a) */
        cml_complex_t z;

        if (a <= -1.0 || a >= 1.0)
        {
                z = complex(cml_acos(1 / a), 0.0);
        }
        else
        {
                if (a >= 0.0)
                {
                        z = complex(0, cml_acosh(1 / a));
                }
                else
                {
                        z = complex(M_PI, -cml_acosh(-1 / a));
                }
        }

        return z;
}

cml_complex_t
cml_complex_acsc(cml_complex_t a)
{                               /* z = acsc(a) */
        cml_complex_t z = cml_complex_inverse(a);
        return cml_complex_asin(z);
}

cml_complex_t
cml_complex_acsc_real(double a)
{                               /* z = acsc(a) */
        cml_complex_t z;

        if (a <= -1.0 || a >= 1.0)
        {
                z = complex(cml_asin(1 / a), 0.0);
        }
        else
        {
                if (a >= 0.0)
                {
                        z = complex(M_PI_2, -cml_acosh(1 / a));
                }
                else
                {
                        z = complex(-M_PI_2, cml_acosh(-1 / a));
                }
        }

        return z;
}

cml_complex_t
cml_complex_acot(cml_complex_t a)
{                               /* z = acot(a) */
        cml_complex_t z;

        if (cml_isnull(CREAL(a)) && cml_isnull(CIMAG(a)))
        {
                z = complex(M_PI_2, 0);
        }
        else
        {
                z = cml_complex_inverse(a);
                z = cml_complex_atan(z);
        }

        return z;
}
