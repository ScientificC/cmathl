#include <stdlib.h>
#include <cml/math.h>
#include <cml/complex.h>


/*
 * exp(Z) = e^Z = (e^a * Cos(b) + e^a * Sin(b)i)
 *
 * @param complex z: Exponent of the function
 *
 * @return complex e^z
 *
 */

complex_t
complex_exp(complex_t z)
{
        /* Declaration of variables and structures */
        complex_t w;
        double n, m, h, x, y;

        /* Mathematical algorithm */
        h = real_exp(z.p[0]);
        n = real_cos(z.p[1]);
        m = real_sin(z.p[1]);
        x = real_mul(h, n);
        y = real_mul(h, m);

        w = complex(x, y);

        /* Return */
        return w;
}


/*
 * logb(z) = log(z)/log(b)
 */

complex_t
complex_log_b(complex_t z, complex_t b)
{
        /* Declaration of variables and structures */
        complex_t k, h, w;

        /* Mathematical algorithm */
        k = complex_log(z);
        h = complex_log(b);
        w = complex_div(k, h);

        /* Return */
        return w;
}


/*
 * Log(z) = ln|z| + i*arg(z)
 */

complex_t
complex_log(complex_t z)
{
        /* Declaration of variables and structures */
        complex_t w;
        double a, x, y;

        /* Mathematical algorithm */
        a = complex_abs(z);
        x = real_log(a);
        y = complex_arg(z);
        w = complex(x, y);

        /* Return */
        return w;
}


complex_t
complex_sqrt(complex_t a)
{                               /* z=sqrt(a) */
        complex_t z;

        if (real_isnull(a.re) && real_isnull(a.im))
        {
                z = complex_zero();
        }
        else
        {
                double x = real_abs(a.re);
                double y = real_abs(a.im);
                double w;

                if (x >= y)
                {
                        double t = y / x;
                        w = real_sqrt(x) * real_sqrt(0.5 * (1.0 + real_sqrt(1.0 + t * t)));
                }
                else
                {
                        double t = x / y;
                        w = real_sqrt(y) * real_sqrt(0.5 * (t + real_sqrt(1.0 + t * t)));
                }

                if (a.re >= 0.0)
                {
                        double ai = a.im;
                        z = complex(w, ai / (2.0 * w));
                }
                else
                {
                        double ai = a.im;
                        double vi = (ai >= 0) ? w : -w;
                        z = complex(ai / (2.0 * vi), vi);
                }
        }

        return z;
}


complex_t
complex_sqrt_real(double x)
{                               /* z=sqrt(x) */
        complex_t z;

        if (x >= 0)
        {
                z = complex(real_sqrt(x), 0.0);
        }
        else
        {
                z = complex(0.0, real_sqrt(-x));
        }

        return z;
}


complex_t
complex_pow (complex_t a, complex_t b)
{                               /* z=a^b */
        complex_t z;

        if (real_isnull(a.re) && real_isnull(a.im))
        {
                if (real_isnull(b.re) && real_isnull(b.im))
                {
                        z = complex(1.0, 0.0);
                }
                else
                {
                        z = complex_zero();
                }
        }
        else if (real_isnull(b.re) && real_isnull(b.im))
        {
                return a;
        }
        else if (real_equal(b.re, -1.0) && real_isnull(b.im))
        {
                return complex_inverse(a);
        }
        else
        {
                double logr = complex_logabs(a);
                double theta = complex_arg(a);

                double br = b.re, bi = b.im;

                double rho = real_exp(logr * br - bi * theta);
                double beta = theta * br + bi * logr;

                z = complex(rho * real_cos(beta), rho * real_sin(beta));
        }

        return z;
}


complex_t
complex_pow_real (complex_t a, double b)
{                               /* z=a^b */
        complex_t z;

        if (real_isnull(a.re) && real_isnull(a.im))
        {
                if (real_isnull(b))
                {
                        z = complex(1.0, 0.0);
                }
                else
                {
                        z = complex_zero();
                }
        }
        else
        {
                double logr = complex_logabs(a);
                double theta = complex_arg(a);
                double rho = real_exp(logr * b);
                double beta = theta * b;
                z = complex(rho * real_cos(beta), rho * real_sin(beta));
        }

        return z;
}
