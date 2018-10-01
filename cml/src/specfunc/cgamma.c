#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <scic/errno.h>
#include <cml/math.h>
#include <cml/complex.h>
#include <cml/specfunc.h>


/*
 * This code originally comes from specfun.f written and copyrighted by
 *      Shanjie Zhang and Jianming Jin
 *
 * but permission is granted to use code in programs
 * "Computation of Special Functions", 1996, John Wiley & Sons, Inc.
 *
 * The fortran code has been hand translated into C by Ulises J. Cornejo Fandos
 *
 */

static const double a[10] =
{
        .08333333333333333, -2.777777777777778e-3,
        7.936507936507937e-4, -5.952380952380952e-4,
        8.417508417508418e-4, -1.917526917526918e-3,
        6.410256410256410e-3, -.02955065359477124,
        .1796443723688307, -1.39243221690590
};

/**
 * Compute the Gamma function for complex argument
 *
 * gr + gi i = Gamma(x + i y) if kf = 1
 * gr + gi i = log(Gamma(x + i y)) if kf = 0
 *
 * @param x real part of the argument
 * @param y imaginary of the argument
 * @param kf an integer flag. If kf, Gamma is computed, if !kf, log(Gamma)
 * @param gr holds the real part of the output
 * @param gi holds the imaginary part of the output is computed
 *
 */
static void
__cml_sp_cgamma(double x, double y, bool kf, double *gr, double *gi)
{
        double x1, y1, x0, z1, z2, th, gr1, gi1, t;
        double sr, si, th1, th2, g0;
        double tmp;
        int na, k, j;

        if (y == 0.0 && x == (double)((int) x) && x <= 0.0)
        {
                *gr = 1.0e300;
                *gi = 0.0;
                return;
        }

        if (x < 0.0)
        {
                x1 = x;
                y1 = y;
                x = -x;
                y = -y;
        }
        else
        {
                y1 = 0.0;
                x1 = x;
        }
        x0 = x;
        na = 0;

        if (x < 7.)
        {
                na = (int)(7 - x);
                x0 = x + na;
        }

        z1 = cml_sqrt(x0 * x0 + y * y);
        th = cml_atan(y / x0);
        *gr = (x0 - .5) * cml_log(z1) - th * y - x0 + 0.5 * cml_log(M_TAU);
        *gi = th * (x0 - 0.5) + y * cml_log(z1) - y;

        for (k = 1; k <= 10; k++)
        {
                t = cml_pow(z1, 1 - 2 * k);
                *gr += a[k - 1] * t * cml_cos((2.0 * k - 1.0) * th);
                *gi -= a[k - 1] * t * cml_sin((2.0 * k - 1.0) * th);
        }

        if (x <= 7.0)
        {
                gr1 = 0.0;
                gi1 = 0.0;
                for (j = 0; j <= na - 1; j++)
                {
                        tmp = x + j;
                        gr1 += 0.5 * cml_log(tmp * tmp + y * y);
                        gi1 += cml_atan(y / (x + j));
                }
                *gr -= gr1;
                *gi -= gi1;
        }

        if (x1 < 0.0)
        {
                z1 = cml_sqrt(x * x + y * y);
                th1 = cml_atan(y / x);
                sr = -cml_sin(M_PI * x) * cml_cosh(M_PI * y);
                si = -cml_cos(M_PI * x) * cml_sinh(M_PI * y);
                z2 = cml_sqrt(sr * sr + si * si);
                th2 = cml_atan(si / sr);

                if (sr < 0.)
                {
                        th2 += M_PI;
                }

                *gr = cml_log(M_PI / (z1 * z2)) - *gr;
                *gi = -th1 - th2 - *gi;
                x = x1;
                y = y1;
        }

        if (kf)
        {
                g0 = cml_exp(*gr);
                *gr = g0 * cml_cos(*gi);
                *gi = g0 * cml_sin(*gi);
        }
}


/**
 * Gamma(z), the Gamma function
 * @param z  a complex number
 * @return  Gamma(z), the Gamma function of z
 */

cml_complex_t
cml_sf_cgamma(cml_complex_t z)
{
        cml_complex_t c;

        __cml_sp_cgamma(CREAL(z), CIMAG(z), true, &CREAL(c), &CIMAG(c));
        return c;
}


/**
 * log(Gamma(z)), the logarithm of the Gamma function
 * @param z  a complex number
 * @return  log(Gamma(z))
 */

cml_complex_t
cml_sf_clngamma(cml_complex_t z)
{
        cml_complex_t c;

        __cml_sp_cgamma(CREAL(z), CIMAG(z), false, &CREAL(c), &CIMAG(c));
        return c;
}
