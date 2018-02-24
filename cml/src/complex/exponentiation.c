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

cml_complex_t
cml_complex_exp(cml_complex_t z)
{
        /* Declaration of variables and structures */
        cml_complex_t w;
        double n, m, h, x, y;

        /* Mathematical algorithm */
        h = cml_exp(z.p[0]);
        n = cml_cos(z.p[1]);
        m = cml_sin(z.p[1]);
        x = cml_mul(h, n);
        y = cml_mul(h, m);

        w = complex(x, y);

        /* Return */
        return w;
}


/*
 * logb(z) = log(z)/log(b)
 */

cml_complex_t
cml_complex_log_b(cml_complex_t z, cml_complex_t b)
{
        /* Declaration of variables and structures */
        cml_complex_t k, h, w;

        /* Mathematical algorithm */
        k = cml_complex_log(z);
        h = cml_complex_log(b);
        w = cml_complex_div(k, h);

        /* Return */
        return w;
}


/*
 * Log(z) = ln|z| + i*arg(z)
 */

cml_complex_t
cml_complex_log(cml_complex_t z)
{
        /* Declaration of variables and structures */
        cml_complex_t w;
        double a, x, y;

        /* Mathematical algorithm */
        a = cml_complex_abs(z);
        x = cml_log(a);
        y = cml_complex_arg(z);
        w = complex(x, y);

        /* Return */
        return w;
}


cml_complex_t
cml_complex_sqrt(cml_complex_t a)
{                               /* z=sqrt(a) */
        cml_complex_t z;

        if (cml_isnull(a.re) && cml_isnull(a.im))
        {
                z = cml_complex_zero();
        }
        else
        {
                double x = cml_abs(a.re);
                double y = cml_abs(a.im);
                double w;

                if (x >= y)
                {
                        double t = y / x;
                        w = cml_sqrt(x) * cml_sqrt(0.5 * (1.0 + cml_sqrt(1.0 + t * t)));
                }
                else
                {
                        double t = x / y;
                        w = cml_sqrt(y) * cml_sqrt(0.5 * (t + cml_sqrt(1.0 + t * t)));
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


cml_complex_t
cml_complex_sqrt_real(double x)
{                               /* z=sqrt(x) */
        cml_complex_t z;

        if (x >= 0)
        {
                z = complex(cml_sqrt(x), 0.0);
        }
        else
        {
                z = complex(0.0, cml_sqrt(-x));
        }

        return z;
}


cml_complex_t
cml_complex_pow (cml_complex_t a, cml_complex_t b)
{                               /* z=a^b */
        cml_complex_t z;

        if (cml_isnull(a.re) && cml_isnull(a.im))
        {
                if (cml_isnull(b.re) && cml_isnull(b.im))
                {
                        z = complex(1.0, 0.0);
                }
                else
                {
                        z = cml_complex_zero();
                }
        }
        else if (cml_isnull(b.re) && cml_isnull(b.im))
        {
                return a;
        }
        else if (cml_equal(b.re, -1.0) && cml_isnull(b.im))
        {
                return cml_complex_inverse(a);
        }
        else
        {
                double logr = cml_complex_logabs(a);
                double theta = cml_complex_arg(a);

                double br = b.re, bi = b.im;

                double rho = cml_exp(logr * br - bi * theta);
                double beta = theta * br + bi * logr;

                z = complex(rho * cml_cos(beta), rho * cml_sin(beta));
        }

        return z;
}


cml_complex_t
cml_complex_pow_real (cml_complex_t a, double b)
{                               /* z=a^b */
        cml_complex_t z;

        if (cml_isnull(a.re) && cml_isnull(a.im))
        {
                if (cml_isnull(b))
                {
                        z = complex(1.0, 0.0);
                }
                else
                {
                        z = cml_complex_zero();
                }
        }
        else
        {
                double logr = cml_complex_logabs(a);
                double theta = cml_complex_arg(a);
                double rho = cml_exp(logr * b);
                double beta = theta * b;
                z = complex(rho * cml_cos(beta), rho * cml_sin(beta));
        }

        return z;
}
