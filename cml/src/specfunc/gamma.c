#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <cml/errno.h>
#include <cml/math.h>
#include <cml/specfunc.h>

static long double const g =  9.65657815377331589457187L;
static long double const exp_g_o_sqrt_2pi = +6.23316569877722552586386e+3L;

static double max_double_arg = 171.0;
static long double max_long_double_arg = 1755.5L;

static long double const a[] = {
        +1.14400529453851095667309e+4L,
        -3.23988020152318335053598e+4L,
        +3.50514523505571666566083e+4L,
        -1.81641309541260702610647e+4L,
        +4.63232990536666818409138e+3L,
        -5.36976777703356780555748e+2L,
        +2.28754473395181007645155e+1L,
        -2.17925748738865115560082e-1L,
        +1.08314836272589368860689e-4L
};

static const long double log_sqrt_2pi = 9.18938533204672741780329736e-1L;

static long double __sf_gammal(long double x);
static long double __duplication_formula(long double two_x);
static long double __cml_lgammal(long double x);

/* Bernoulli numbers B(2),B(4),B(6),...,B(20).  Only B(2),...,B(6)
   currently used. */

static const long double B[] = {
        1.0L / (long double)(6 * 2 * 1),
        -1.0L / (long double)(30 * 4 * 3),
        1.0L / (long double)(42 * 6 * 5),
        -1.0L / (long double)(30 * 8 * 7),
        5.0L / (long double)(66 * 10 * 9),
        -691.0L / (long double)(2730 * 12 * 11),
        7.0L / (long double)(6 * 14 * 13),
        -3617.0L / (long double)(510 * 16 * 15),
        43867.0L / (long double)(796 * 18 * 17),
        -174611.0L / (long double)(330 * 20 * 19)
};

static long double __lngamma_asymptotic_expansion(long double x);


/*
 * This function uses Lanczos' expression to calculate Gamma(x) for real
 * x, where -(max_double_arg - 1) < x < max_double_arg.
 * Note the Gamma function is meromorphic in the complex plane and has
 * poles at the nonpositive integers.
 * Tests for x a positive integer or a half positive integer give a
 * maximum absolute relative error of about 1.9e-16.
 *
 * If x > max_double_arg, then one should either use cml_sf_gammal(x)
 * or calculate lnGamma(x).
 * Note that for x < 0, ln (Gamma(x)) may be a complex number.
 *
 * @param double x Argument of the Gamma function.
 *
 * @return double If x is positive and is less than max_double_arg then Gamma(x) is
 * returned and if x > max_double_arg then DBL_MAX is returned.  If x is
 * a nonpositive integer i.e. x is a pole, then DBL_MAX is returned
 * ( note that Gamma(x) changes sign on each side of the pole).  If x is
 * nonpositive nonintegral, then if Gamma(x) > DBL_MAX, then DBL_MAX is
 * returned and if Gamma(x) < -DBL_MAX, then -DBL_MAX is returned.
 *
 */

double
cml_sf_gamma(double x)
{
        long double g;

        if (x > max_double_arg)
        {
                return DBL_MAX;
        }

        g = __sf_gammal((long double) x);

        if (cml_abs(g) < DBL_MAX)
        {
                return (double) g;
        }

        return (g < 0.0L) ?
               -DBL_MAX :
               DBL_MAX;
}


/*
 * This function calculates the natural log of Gamma(x) for positive real
 * x.
 *
 * Assuming that Gamma_Function_Max_Arg() = 171, then
 * If 0 < x <= 171, then ln(gamma(x)) is calculated by taking the natural
 * log of the result from Gamma_Function(x).  If x > 171, then
 * ln(gamma(x)) is calculated using the asymptotic expansion
 *     ln(gamma(x)) ~ ln(2sqrt(2pi)) - x + (x - 1/2) ln x +
 *                    Sum B[2j] / [ 2j * (2j-1) * x^(2j-1) ], summed over
 * j from 1 to 3 and where B[2j] is the 2j-th Bernoulli number.
 *
 */

double
cml_sf_lngamma(double x)
{
        if (x <= max_double_arg)
        {
                return cml_log(cml_sf_gamma(x));
        }

        return (double) __lngamma_asymptotic_expansion((long double) x);
}


/*
 * This function uses Lanczos' expression to calculate Gamma(x) for real
 * x, where -(max_long_double_arg - 1) < x < max_long_double_arg.
 * Note the Gamma function is meromorphic in the complex plane and has
 * poles at the nonpositive integers.
 * Tests for x a positive integer or a half positive integer give a
 * maximum absolute relative error of about 3.5e-16.
 *
 * If x > max_long_double_arg, then one should use lnGamma(x).
 * Note that for x < 0, ln (Gamma(x)) may be a complex number.
 *
 * @param long double x Argument of the Gamma function.
 *
 * @return double If x is positive and is less than max_long_double_arg, then Gamma(x)
 * is returned and if x > max_long_double_arg, then LDBL_MAX is returned.
 * If x is a nonpositive integer i.e. x is a pole, then LDBL_MAX is
 * returned ( note that Gamma(x) changes sign on each side of the pole).
 * If x is nonpositive nonintegral, then if x > -(max_long_double_arg + 1)
 * then Gamma(x) is returned otherwise 0.0 is returned.
 *
 */

static long double
__sf_gammal(long double x)
{
        long double sin_x;
        long double rg;
        long int ix;

        if ( x > 0.0L )
        {
                if (x <= max_long_double_arg)
                {
                        return __cml_lgammal(x);
                }
                else
                {
                        return LDBL_MAX;
                }
        }

        if (x > -(long double)LONG_MAX)
        {
                ix = (long int) x;

                if (x == (long double) ix)
                {
                        return LDBL_MAX;
                }
        }

        sin_x = (long double) cml_sin(M_PI * (double) x);

        if (sin_x == 0.0L)
        {
                return LDBL_MAX;
        }

        if (x < -(max_long_double_arg - 1.0L))
        {
                return 0.0L;
        }

        rg = __cml_lgammal(1.0L - x) * sin_x / (long double) M_PI;

        if (rg != 0.0L)
        {
                return (1.0L / rg);
        }

        return LDBL_MAX;
}


/*
 * This function uses Lanczos' expression to calculate Gamma(x) for real
 * x, where 0 < x <= 900. For 900 < x < 1755.5, the duplication formula
 * is used.
 *
 * The major source of relative error is in the use of the cml library
 * function cml_pow(). The results have a relative error of about 10^-16.
 * except near x = 0.
 *
 * If x > 1755.5, then one should calculate lnGamma(x).
 *
 */

static long double
__cml_lgammal(long double x)
{
        long double xx = (x < 1.0L) ? x + 1.0L : x;
        long double temp;
        int const n = sizeof(a) / sizeof(long double);
        int i;

        if (x > 1755.5L)
        {
                return LDBL_MAX;
        }

        if (x > 900.0L)
        {
                return __duplication_formula(x);
        }

        temp = 0.0L;
        for (i = n-1; i >= 0; i--)
        {
                temp += (a[i] / (xx + (long double) i));
        }

        temp += 1.0L;
        temp *= (cml_pow((g + xx - 0.5L) / M_E, xx - 0.5L) / exp_g_o_sqrt_2pi);

        return (x < 1.0L) ?
               temp/x :
               temp;
}


/*
 * This function returns the Gamma(two_x) using the duplication formula
 * Gamma(2x) = (2^(2x-1) / sqrt(pi)) Gamma(x) Gamma(x+1/2).
 */

static long double
__duplication_formula(long double two_x)
{
        long double x = 0.5L * two_x;
        long double g;
        int n = (int) two_x - 1;

        g = cml_pow(2.0L, two_x - 1.0L - (long double) n);
        g = cml_ldexp(g,n);
        g /= cml_sqrt((long double) M_PI);
        g *= __sf_gammal(x);
        g *= __sf_gammal(x + 0.5L);

        return g;
}


static long double
__lngamma_asymptotic_expansion(long double x)
{
        const int m = sizeof(B) / sizeof(long double);
        long double term[m];
        long double sum = 0.0L;
        long double xx = x * x;
        long double xj = x;
        long double lngamma = log_sqrt_2pi - xj + (xj - 0.5L) * (long double) cml_log((double) xj);

        int i;

        for (i = 0; i < m; i++)
        {
                term[i] = B[i] / xj;
                xj *= xx;
        }

        for (i = m - 1; i >= 0; i--)
        {
                sum += term[i];
        }

        return lngamma + sum;
}
