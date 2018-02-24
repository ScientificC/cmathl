#include <stdlib.h>
#include <cml/math.h>

/*
 * cos(Z) = (cos(a) * ((e^b - e^-b) / 2) + (sin(a) * (e^b + e^-b) / 2))i
 * cos(Z) = (cos(a) * sinh(b)) + (sin(a) * cosh(b))i
 *
 * @param complex_t z
 *
 * @return complex_t cos(z)
 *
 */

complex_t
complex_cos(complex_t z)
{
        double k = real_cos(z.p[0]);

        if (real_isnull(z.im))
        {
                return complex(k, 0.0);
        }

        complex_t w;
        double h, a, b, n, m;

        h = real_sin(z.p[0]);
        a = real_sinh(z.p[1]);
        b = real_cosh(z.p[1]);
        n = real_mul(k, a);
        m = real_mul(h, b);

        w = complex(n, m);

        return w;
}


complex_t
complex_cot(complex_t z)
{
        complex_t s = complex_sin(z);
        double a = complex_abs(s);
        if (!real_isnull(a))
        {
                return complex_nan();
        }

        complex_t c, w;

        c = complex_cos(z);
        w = complex_div(c, s);

        return w;
}


complex_t
complex_csc(complex_t z)
{
        complex_t s = complex_sin(z);
        double a = complex_abs(s);
        if (!real_isnull(a))
        {
                return complex_nan();
        }

        complex_t w;

        w = complex_inverse(s);

        return w;
}


complex_t
complex_sec(complex_t z)
{
        complex_t c = complex_cos(z);
        double a = complex_abs(c);
        if (!real_isnull(a))
        {
                return complex_nan();
        }

        complex_t w;

        w = complex_inverse(c);

        return w;
}


/*
 * sin(Z) = (sin(a) * ((e^b + e^-b) / 2) + (Cos(a) * (e^b - e^-b) / 2))i
 * sin(Z) = (sin(a) * cosh(b)) + (cos(a) * sinh(b))i
 *
 * @param complex_t z
 *
 * @return complex_t sin(z)
 *
 */

complex_t
complex_sin(complex_t z)
{
        double k = real_sin(z.re);

        if (real_isnull(z.im))
        {
                return complex(k, 0.0);
        }

        complex_t w;
        double h, a, b, n, m;

        h = real_cos(z.re);
        a = real_cosh(z.im);
        b = real_sinh(z.im);

        n = real_mul(k, a);
        m = real_mul(h, b);

        w = complex(n, m);

        return w;
}


complex_t
complex_tan(complex_t a)
{                               /* z = tan(a) */
        complex_t z;

        double R = a.re, I = a.im;
        double D = real_pow(real_cos(R), 2.0) + real_pow(real_sinh(I), 2.0);

        if (real_abs(I) < 1)
        {
                z = complex(0.5 * real_sin(2 * R) / D, 0.5 * real_sinh(2 * I) / D);
        }
        else
        {
                double F = 1 + real_pow(real_cos(R)/real_sinh(I), 2.0);

                z = complex(0.5 * real_sin(2 * R) / D, 1 / (doubleanh(I) * F));
        }

        return z;
}


complex_t
complex_asin(complex_t a)
{                               /* z = asin(a) */
        double R = a.re, I = a.im;
        complex_t z;

        if (real_isnull(I))
        {
                z = complex_asin_real(R);
        }
        else
        {
                double x = real_abs(R), y = real_abs(I);
                double r = real_hypot(x + 1, y), s = real_hypot(x - 1, y);
                double A = 0.5 * (r + s);
                double B = x / A;
                double y2 = y * y;

                double real, imag;

                const double A_crossover = 1.5, B_crossover = 0.6417;

                if (B <= B_crossover)
                {
                        real = real_asin(B);
                }
                else
                {
                        if (x <= 1)
                        {
                                double D = 0.5 * (A + x) * (y2 / (r + x + 1) + (s + (1 - x)));
                                real = real_atan(x / real_sqrt(D));
                        }
                        else
                        {
                                double Apx = A + x;
                                double D = 0.5 * (Apx / (r + x + 1) + Apx / (s + (x - 1)));
                                real = real_atan(x / (y * real_sqrt(D)));
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

                        imag = real_log1p(Am1 + real_sqrt(Am1 * (A + 1)));
                }
                else
                {
                        imag = real_log(A + real_sqrt(A * A - 1));
                }

                z = complex((R >= 0) ? real : -real, (I >= 0) ? imag : -imag);
        }

        return z;
}

complex_t
complex_asin_real(double a)
{                               /* z = asin(a) */
        complex_t z;

        if (real_abs(a) <= 1.0)
        {
                z = complex(real_asin(a), 0.0);
        }
        else
        {
                if (a < 0.0)
                {
                        z = complex(-M_PI_2, real_acosh(-a));
                }
                else
                {
                        z = complex(M_PI_2, -real_acosh(a));
                }
        }

        return z;
}

complex_t
complex_acos(complex_t a)
{                               /* z = acos(a) */
        double R = a.re, I = a.im;
        complex_t z;

        if (I == 0)
        {
                z = complex_acos_real(R);
        }
        else
        {
                double x = real_abs(R), y = real_abs(I);
                double r = real_hypot(x + 1, y), s = real_hypot(x - 1, y);
                double A = 0.5 * (r + s);
                double B = x / A;
                double y2 = y * y;

                double real, imag;

                const double A_crossover = 1.5, B_crossover = 0.6417;

                if (B <= B_crossover)
                {
                        real = real_acos(B);
                }
                else
                {
                        if (x <= 1)
                        {
                                double D = 0.5 * (A + x) * (y2 / (r + x + 1) + (s + (1 - x)));
                                real = real_atan(real_sqrt(D) / x);
                        }
                        else
                        {
                                double Apx = A + x;
                                double D = 0.5 * (Apx / (r + x + 1) + Apx / (s + (x - 1)));
                                real = real_atan((y * real_sqrt(D)) / x);
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

                        imag = real_log1p(Am1 + real_sqrt(Am1 * (A + 1)));
                }
                else
                {
                        imag = real_log(A + real_sqrt(A * A - 1));
                }

                z = complex((R >= 0) ? real : M_PI - real, (I >= 0) ? -imag : imag);
        }

        return z;
}

complex_t
complex_acos_real(double a)
{                               /* z = acos(a) */
        complex_t z;

        if (real_abs(a) <= 1.0)
        {
                z = complex(real_acos(a), 0);
        }
        else
        {
                if (a < 0.0)
                {
                        z = complex(M_PI, -real_acosh(-a));
                }
                else
                {
                        z = complex(0, real_acosh(a));
                }
        }

        return z;
}

complex_t
complex_atan(complex_t a)
{                               /* z = atan(a) */
        double R = a.re, I = a.im;
        complex_t z;

        if (real_isnull(I))
        {
                z = complex(real_atan(R), 0);
        }
        else
        {
                /* FIXME: This is a naive implementation which does not fully
                   take into account cancellation errors, overflow, underflow
                   etc.  It would benefit from the Hull et al treatment. */

                double r = real_hypot(R, I);

                double imag;

                double u = 2 * I / (1 + r * r);

                /* FIXME: the following cross-over should be optimized but 0.1
                   seems to work ok */

                if (real_abs(u) < 0.1)
                {
                        imag = 0.25 * (real_log1p(u) - real_log1p(-u));
                }
                else
                {
                        double A = real_hypot(R, I + 1);
                        double B = real_hypot(R, I - 1);
                        imag = 0.5 * real_log(A / B);
                }

                if (real_isnull(R))
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
                        z = complex(0.5 * real_atan2(2 * R, ((1 + r) * (1 - r))), imag);
                }
        }

        return z;
}

complex_t
complex_asec(complex_t a)
{                               /* z = asec(a) */
        complex_t z = complex_inverse(a);
        return complex_acos(z);
}

complex_t
complex_asec_real(double a)
{                               /* z = asec(a) */
        complex_t z;

        if (a <= -1.0 || a >= 1.0)
        {
                z = complex(real_acos(1 / a), 0.0);
        }
        else
        {
                if (a >= 0.0)
                {
                        z = complex(0, real_acosh(1 / a));
                }
                else
                {
                        z = complex(M_PI, -real_acosh(-1 / a));
                }
        }

        return z;
}

complex_t
complex_acsc(complex_t a)
{                               /* z = acsc(a) */
        complex_t z = complex_inverse(a);
        return complex_asin(z);
}

complex_t
complex_acsc_real(double a)
{                               /* z = acsc(a) */
        complex_t z;

        if (a <= -1.0 || a >= 1.0)
        {
                z = complex(real_asin(1 / a), 0.0);
        }
        else
        {
                if (a >= 0.0)
                {
                        z = complex(M_PI_2, -real_acosh(1 / a));
                }
                else
                {
                        z = complex(-M_PI_2, real_acosh(-1 / a));
                }
        }

        return z;
}

complex_t
complex_acot(complex_t a)
{                               /* z = acot(a) */
        complex_t z;

        if (real_isnull(a.re) && real_isnull(a.im))
        {
                z = complex(M_PI_2, 0);
        }
        else
        {
                z = complex_inverse(a);
                z = complex_atan(z);
        }

        return z;
}
