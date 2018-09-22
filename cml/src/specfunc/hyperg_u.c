#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <scic/errno.h>
#include <cml/math.h>
#include <cml/specfunc.h>


/*
 * The functions chgul, chgus, chgubi and chguit come from the Scipy
 * library. They were originally written in fortran and have translated into
 * using f2c and a few hand corrections
 *
 *          Shanjie Zhang and Jianming Jin
 *
 * Copyrighted but permission granted to use code in programs.
 * Buy their book "Computation of Special Functions", 1996,
 * John Wiley & Sons, Inc.
 */

static int c_n1 = -1;

static int chgu_(double *a, double *b, double *x, double *hu, int *md);
static int chgul_(double *, double *, double *, double *, int *);
static int chgus_(double *, double *, double *, double *, int *);
static int chgubi_(double *, double *, double *, double *, int *);
static int chguit_(double *, double *, double *, double *, int *);
static int psi_spec__(double *x, double *ps);


static int
gamma2_(double *x, double *res)
{
        *res = cml_sf_gamma(*x);
        return 0;
}


static double
pow_dd(double *x, double *y)
{
        return cml_pow(*x, *y);
}


static double
pow_di(double *x, int *p)
{
        return cml_pow_int(*x, *p);
}


static int
pow_ii(int *x, int *p)
{
        double xd = (double) (*x);
        return (int) cml_pow_int(xd, *p);
}


double
cml_sf_hyperg_U(double a, double b, double x)
{
        double hu;
        int md;
        chgu_(&a, &b, &x, &hu, &md);
        return hu;
}


static int
chguit_(double *a, double *b, double *x,
        double *hu, int *id)
{
        /* Initialized data */

        static double t[30] =
        {
                .0259597723012478, .0778093339495366,
                .129449135396945, .180739964873425, .231543551376029,
                .281722937423262, .331142848268448, .379670056576798,
                .427173741583078, .473525841761707, .51860140005857,
                .562278900753945, .60444059704851, .644972828489477,
                .683766327381356, .72071651335573, .755723775306586,
                .788693739932264, .819537526162146, .84817198478593,
                .874519922646898, .898510310810046, .920078476177628,
                .939166276116423, .955722255839996, .969701788765053,
                .981067201752598, .989787895222222, .995840525118838,
                .999210123227436
        };
        static double w[30] =
        {
                .0519078776312206, .0517679431749102,
                .051488451500981, .0510701560698557, .0505141845325094,
                .0498220356905502, .0489955754557568, .0480370318199712,
                .0469489888489122, .0457343797161145, .0443964787957872,
                .0429388928359356, .0413655512355848, .0396806954523808,
                .0378888675692434, .0359948980510845, .0340038927249464,
                .0319212190192963, .029752491500789, .0275035567499248,
                .0251804776215213, .0227895169439978, .0203371207294572,
                .0178299010142074, .0152746185967848, .0126781664768159,
                .010047557182288, .00738993116334531, .00471272992695363,
                .00202681196887362
        };

        /* System generated locals */
        int i__1;
        double d__1;

        /* Local variables */
        double c__, d__, g;
        int j, k, m;
        double s, a1, b1, f1, f2, t1, t2, t3, t4, ga, hu0, hu1, hu2;

        /*       ====================================================== */
        /*       Purpose: Compute hypergeometric function U(a,b,x) by */
        /*                using Gaussian-Legendre integration (n=60) */
        /*       Input  : a  --- Parameter ( a > 0 ) */
        /*                b  --- Parameter */
        /*                x  --- Argument ( x > 0 ) */
        /*       Output:  HU --- U(a,b,z) */
        /*                ID --- Estimated number of significant digits */
        /*       Routine called: GAMMA2 for computing â(x) */
        /*       ====================================================== */

        *id = 7;
        a1 = *a - 1.;
        b1 = *b - *a - 1.;
        c__ = 12. / *x;
        hu0 = 0.;
        for (m = 10; m <= 100; m += 5)
        {
                hu1 = 0.;
                g = c__ * .5 / m;
                d__ = g;
                i__1 = m;
                for (j = 1; j <= i__1; ++j)
                {
                        s = 0.;
                        for (k = 1; k <= 30; ++k)
                        {
                                t1 = d__ + g * t[k - 1];
                                t2 = d__ - g * t[k - 1];
                                d__1 = t1 + 1.;
                                f1 = cml_exp(-(*x) * t1) * pow_dd(&t1, &a1) * pow_dd(&d__1, &b1);
                                d__1 = t2 + 1.;
                                f2 = cml_exp(-(*x) * t2) * pow_dd(&t2, &a1) * pow_dd(&d__1, &b1);
                                s += w[k - 1] * (f1 + f2);
                        }
                        hu1 += s * g;
                        d__ += g * 2.;
                }
                if (cml_abs(1. - hu0 / hu1) < 1e-7)
                {
                        break;
                }
                hu0 = hu1;
        }

        gamma2_(a, &ga);
        hu1 /= ga;
        for (m = 2; m <= 10; m += 2)
        {
                hu2 = 0.;
                g = .5 / m;
                d__ = g;
                i__1 = m;
                for (j = 1; j <= i__1; ++j)
                {
                        s = 0.;
                        for (k = 1; k <= 30; ++k)
                        {
                                t1 = d__ + g * t[k - 1];
                                t2 = d__ - g * t[k - 1];
                                t3 = c__ / (1. - t1);
                                t4 = c__ / (1. - t2);
                                d__1 = t3 + 1.;
                                f1 = t3 * t3 / c__ * cml_exp(-(*x) * t3) * pow_dd(&t3, &a1) *
                                     pow_dd(&d__1, &b1);
                                d__1 = t4 + 1.;
                                f2 = t4 * t4 / c__ * cml_exp(-(*x) * t4) * pow_dd(&t4, &a1) *
                                     pow_dd(&d__1, &b1);
                                s += w[k - 1] * (f1 + f2);
                        }
                        hu2 += s * g;
                        d__ += g * 2.;
                }
                if (cml_abs(1. - hu0 / hu2) < 1e-7)
                {
                        break;
                }
                hu0 = hu2;
        }

        gamma2_(a, &ga);
        hu2 /= ga;
        *hu = hu1 + hu2;
        return 0;
}


static int
chgu_(double *a, double *b, double *x,
      double *hu, int *md)
{
        /* Local variables */
        double a00, aa, b00;
        int id;
        int bn;
        int id1;
        int bl1, bl2, bl3, il1, il2, il3;
        double hu1, d__1;


        /*       ======================================================= */
        /*       Purpose: Compute the confluent hypergeometric function */
        /*                U(a,b,x) */
        /*       Input  : a  --- Parameter */
        /*                b  --- Parameter */
        /*                x  --- Argument  ( x > 0 ) */
        /*       Output:  HU --- U(a,b,x) */
        /*                MD --- Method code */
        /*       Routines called: */
        /*            (1) CHGUS for small x ( MD=1 ) */
        /*            (2) CHGUL for large x ( MD=2 ) */
        /*            (3) CHGUBI for int b ( MD=3 ) */
        /*            (4) CHGUIT for numerical integration ( MD=4 ) */
        /*       ======================================================= */

        aa = *a - *b + 1.;
        il1 = (*a == (double)((int)(*a))) && (*a <= 0.);
        il2 = (aa == (double)((int) aa)) && (aa <= 0.);
        il3 = ((cml_abs(*a * (*a - *b + 1.)) / *x) <= 2.);
        bl1 = *x <= 5. || (*x <= 10. && *a <= 2.);
        bl2 = (*x > 5. && *x <= 12.5) && (*a >= 1. && *b >= *a + 4.);
        bl3 = *x > 12.5 && *a >= 5. && *b >= *a + 5.;
        bn = (*b == (double)((int)(*b))) && (*b != 0.);
        id1 = -100;
        hu1 = 0.;
        if (*b != (double)((int)(*b)))
        {
                chgus_(a, b, x, hu, &id1);
                *md = 1;
                if (id1 >= 6)
                {
                        return 0;
                }
                hu1 = *hu;
        }
        if (il1 || il2 || il3)
        {
                chgul_(a, b, x, hu, &id);
                *md = 2;
                if (id >= 6)
                {
                        return 0;
                }
                if (id1 > id)
                {
                        *md = 1;
                        id = id1;
                        *hu = hu1;
                }
        }
        if (*a >= 0.)
        {
                if (bn && (bl1 || bl2 || bl3))
                {
                        chgubi_(a, b, x, hu, &id);
                        *md = 3;
                }
                else
                {
                        chguit_(a, b, x, hu, &id);
                        *md = 4;
                }
        }
        else
        {
                if (*b <= *a)
                {
                        a00 = *a;
                        b00 = *b;
                        *a = *a - *b + 1.;
                        *b = 2. - *b;
                        chguit_(a, b, x, hu, &id);
                        d__1 = 1. - b00;
                        *hu = pow_dd(x, &d__1) **hu;
                        *a = a00;
                        *b = b00;
                        *md = 4;
                }
                else if (bn && !il1)
                {
                        chgubi_(a, b, x, hu, &id);
                        *md = 3;
                }
        }
        if (id < 6)
        {
                printf("No accurate results obtained in chgu");
        }
        return 0;
}


static int
chgus_(double *a, double *b, double *x, double *hu, int *id)
{
        /* System generated locals */
        double d__1;

        /* Local variables */
        int j;
        double d1, d2, h0, r1, r2, ga, gb, pi, gb2, hu0, xg1, xg2, gab,
               hua, hmin, hmax;


        /*       ====================================================== */
        /*       Purpose: Compute confluent hypergeometric function */
        /*                U(a,b,x) for small argument x */
        /*       Input  : a  --- Parameter */
        /*                b  --- Parameter ( b <> 0,-1,-2,...) */
        /*                x  --- Argument */
        /*       Output:  HU --- U(a,b,x) */
        /*                ID --- Estimated number of significant digits */
        /*       Routine called: GAMMA2 for computing gamma function */
        /*       ====================================================== */

        *id = -100;
        pi = 3.141592653589793;
        gamma2_(a, &ga);
        gamma2_(b, &gb);
        xg1 = *a + 1. - *b;
        gamma2_(&xg1, &gab);
        xg2 = 2. - *b;
        gamma2_(&xg2, &gb2);
        hu0 = pi / cml_sin(pi **b);
        r1 = hu0 / (gab * gb);
        d__1 = 1. - *b;
        r2 = hu0 * pow_dd(x, &d__1) / (ga * gb2);
        *hu = r1 - r2;
        hmax = 0.;
        hmin = 1e300;
        h0 = 0.;
        for (j = 1; j <= 150; ++j)
        {
                r1 = r1 * (*a + j - 1.) / (j * (*b + j - 1.)) **x;
                r2 = r2 * (*a - *b + j) / (j * (1. - *b + j)) **x;
                *hu = *hu + r1 - r2;
                hua = cml_abs(*hu);
                if (hua > hmax)
                {
                        hmax = hua;
                }
                if (hua < hmin)
                {
                        hmin = hua;
                }
                if (cml_abs(*hu - h0) < cml_abs(*hu) * 1e-15)
                {
                        break;
                }
                h0 = *hu;
        }

        d1 = cml_log_b(hmax, 10.0);
        d2 = 0.;
        if (hmin != 0.)
        {
                d2 = cml_log_b(hmin, 10.0);
        }
        *id = (int)(15 - cml_abs(d1 - d2));
        return 0;
}


static int
chgul_(double *a, double *b, double *x, double *hu, int *id)
{
        /* System generated locals */
        int i__1;
        double d__1;

        /* Local variables */
        int k;
        double r__, r0, aa, ra;
        int nm;
        int il1, il2;


        /*       ======================================================= */
        /*       Purpose: Compute the confluent hypergeometric function */
        /*                U(a,b,x) for large argument x */
        /*       Input  : a  --- Parameter */
        /*                b  --- Parameter */
        /*                x  --- Argument */
        /*       Output:  HU --- U(a,b,x) */
        /*                ID --- Estimated number of significant digits */
        /*       ======================================================= */

        r0 = 0.;
        *id = -100;
        aa = *a - *b + 1.;
        il1 = (*a == (double)((int)(*a))) && (*a <= 0.);
        il2 = (aa == (double)((int) aa)) && (aa <= 0.);
        nm = 0;
        if (il1)
        {
                nm = (int) cml_abs(*a);
        }
        if (il2)
        {
                nm = (int) cml_abs(aa);
        }
        if (il1 || il2)
        {
                *hu = 1.;
                r__ = 1.;
                i__1 = nm;
                for (k = 1; k <= i__1; ++k)
                {
                        r__ = -r__ * (*a + k - 1.) * (*a - *b + k) / (k **x);
                        *hu += r__;
                }
                d__1 = -(*a);
                *hu = pow_dd(x, &d__1) **hu;
                *id = 10;
        }
        else
        {
                *hu = 1.;
                r__ = 1.;
                for (k = 1; k <= 25; ++k)
                {
                        r__ = -r__ * (*a + k - 1.) * (*a - *b + k) / (k **x);
                        ra = cml_abs(r__);
                        if ((k > 5 && ra >= r0) || ra < 1e-15)
                        {
                                break;
                        }
                        r0 = ra;
                        *hu += r__;
                }
                *id = (int) cml_abs(cml_log_b(ra, 10.0));
                d__1 = -(*a);
                *hu = pow_dd(x, &d__1) **hu;
        }
        return 0;
}


static int
chgubi_(double *a, double *b, double *x,
        double *hu, int *id)
{
        /* System generated locals */
        int i__1;
        double d__1;

        /* Local variables */
        int j, k, m, n;
        double r__, a0, a1, a2, h0, s0, s1, s2, ga, el, sa, sb, ua, ub,
               hw, rn, ps, da1, da2, db1, ga1, db2;
        int id1, id2;
        double hm1, hm2, hm3, hu1, hu2, rn1, hmin, hmax;


        /*       ====================================================== */
        /*       Purpose: Compute confluent hypergeometric function */
        /*                U(a,b,x) with int b ( b = ñ1,ñ2,... ) */
        /*       Input  : a  --- Parameter */
        /*                b  --- Parameter */
        /*                x  --- Argument */
        /*       Output:  HU --- U(a,b,x) */
        /*                ID --- Estimated number of significant digits */
        /*       Routines called: */
        /*            (1) GAMMA2 for computing gamma function â(x) */
        /*            (2) PSI_SPEC for computing psi function */
        /*       ====================================================== */

        *id = -100;
        el = .5772156649015329;
        n = (int) cml_abs(*b - 1);
        rn1 = 1.;
        rn = 1.;
        i__1 = n;
        for (j = 1; j <= i__1; ++j)
        {
                rn *= j;
                if (j == n - 1)
                {
                        rn1 = rn;
                }
        }
        psi_spec__(a, &ps);
        gamma2_(a, &ga);
        if (*b > 0.)
        {
                a0 = *a;
                a1 = *a - n;
                a2 = a1;
                gamma2_(&a1, &ga1);
                i__1 = n - 1;
                ua = pow_ii(&c_n1, &i__1) / (rn * ga1);
                i__1 = -n;
                ub = rn1 / ga * pow_di(x, &i__1);
        }
        else
        {
                a0 = *a + n;
                a1 = a0;
                a2 = *a;
                gamma2_(&a1, &ga1);
                i__1 = n - 1;
                ua = pow_ii(&c_n1, &i__1) / (rn * ga) * pow_di(x, &n);
                ub = rn1 / ga1;
        }
        hm1 = 1.;
        r__ = 1.;
        hmax = 0.;
        hmin = 1e300;
        h0 = 0.;
        for (k = 1; k <= 150; ++k)
        {
                r__ = r__ * (a0 + k - 1.) **x / ((n + k) * k);
                hm1 += r__;
                hu1 = cml_abs(hm1);
                if (hu1 > hmax)
                {
                        hmax = hu1;
                }
                if (hu1 < hmin)
                {
                        hmin = hu1;
                }
                if (cml_abs(hm1 - h0) < cml_abs(hm1) * 1e-15)
                {
                        break;
                }
                h0 = hm1;
        }

        da1 = cml_log_b(hmax, 10.0);
        da2 = 0.;
        if (hmin != 0.)
        {
                da2 = cml_log_b(hmin, 10.0);
        }
        *id = (int)(15 - cml_abs(da1 - da2));
        hm1 *= cml_log(*x);
        s0 = 0.;
        i__1 = n;
        for (m = 1; m <= i__1; ++m)
        {
                if (*b >= 0.)
                {
                        s0 -= 1. / m;
                }
                if (*b < 0.)
                {
                        s0 += (1. - *a) / (m * (*a + m - 1.));
                }
        }
        hm2 = ps + el * 2. + s0;
        r__ = 1.;
        hmax = 0.;
        hmin = 1e300;
        for (k = 1; k <= 150; ++k)
        {
                s1 = 0.;
                s2 = 0.;
                if (*b > 0.)
                {
                        i__1 = k;
                        for (m = 1; m <= i__1; ++m)
                        {
                                s1 -= (m + *a * 2. - 2.) / (m * (m + *a - 1.));
                        }
                        i__1 = n;
                        for (m = 1; m <= i__1; ++m)
                        {
                                s2 += 1. / (k + m);
                        }
                }
                else
                {
                        i__1 = k + n;
                        for (m = 1; m <= i__1; ++m)
                        {
                                s1 += (1. - *a) / (m * (m + *a - 1.));
                        }
                        i__1 = k;
                        for (m = 1; m <= i__1; ++m)
                        {
                                s2 += 1. / m;
                        }
                }
                hw = el * 2. + ps + s1 - s2;
                r__ = r__ * (a0 + k - 1.) **x / ((n + k) * k);
                hm2 += r__ * hw;
                hu2 = cml_abs(hm2);
                if (hu2 > hmax)
                {
                        hmax = hu2;
                }
                if (hu2 < hmin)
                {
                        hmin = hu2;
                }
                if (cml_abs((hm2 - h0) / hm2) < 1e-15)
                {
                        break;
                }
                h0 = hm2;
        }

        db1 = cml_log_b(hmax, 10.0);
        db2 = 0.;
        if (hmin != 0.)
        {
                db2 = cml_log_b(hmin, 10.0);
        }
        id1 = (int)(15 - (cml_abs(db1 - db2)));
        if (id1 < *id)
        {
                *id = id1;
        }
        hm3 = 1.;
        if (n == 0)
        {
                hm3 = 0.;
        }
        r__ = 1.;
        i__1 = n - 1;
        for (k = 1; k <= i__1; ++k)
        {
                r__ = r__ * (a2 + k - 1.) / ((k - n) * k) **x;
                hm3 += r__;
        }
        sa = ua * (hm1 + hm2);
        sb = ub * hm3;
        *hu = sa + sb;
        id2 = 0;
        if (sa != 0.)
        {
                d__1 = cml_abs(sa);
                id1 = (int) cml_log_b(d__1, 10.0);
        }
        if (*hu != 0.)
        {
                d__1 = cml_abs(*hu);
                id2 = (int) cml_log_b(d__1, 10.0);
        }
        if (sa * sb < 0.)
        {
                *id -= cml_abs(id1 - id2);
        }
        return 0;
}


static int psi_spec__(double *x, double *ps)
{
        /* System generated locals */
        int i__1;

        /* Local variables */
        int k, n;
        double s, a1, a2, a3, a4, a5, a6, a7, a8, x2, el, xa, pi;


        /*       ====================================== */
        /*       Purpose: Compute Psi function */
        /*       Input :  x  --- Argument of psi(x) */
        /*       Output:  PS --- psi(x) */
        /*       ====================================== */

        xa = cml_abs(*x);
        pi = 3.141592653589793;
        el = .5772156649015329;
        s = 0.;
        if ((*x == (double)((int)(*x))) && (*x <= 0.))
        {
                *ps = 1e300;
                return 0;
        }
        else if (xa == (double)((int) xa))
        {
                n = (int) xa;
                i__1 = n - 1;
                for (k = 1; k <= i__1; ++k)
                {
                        s += 1. / k;
                }
                *ps = -el + s;
        }
        else if (xa + .5 == (double)((int)(xa + .5)))
        {
                n = (int)(xa - .5);
                i__1 = n;
                for (k = 1; k <= i__1; ++k)
                {
                        s += 1. / (k * 2. - 1.);
                }
                *ps = -el + s * 2. - 1.386294361119891;
        }
        else
        {
                if (xa < 10.)
                {
                        n = 10 - (int) xa;
                        i__1 = n - 1;
                        for (k = 0; k <= i__1; ++k)
                        {
                                s += 1. / (xa + k);
                        }
                        xa += n;
                }
                x2 = 1. / (xa * xa);
                a1 = -.08333333333333;
                a2 = .0083333333333333333;
                a3 = -.0039682539682539683;
                a4 = .0041666666666666667;
                a5 = -.0075757575757575758;
                a6 = .021092796092796093;
                a7 = -.083333333333333333;
                a8 = .4432598039215686;
                *ps = cml_log(xa) - .5 / xa + x2 * (((((((a8 * x2 + a7) * x2 + a6) * x2 +
                                                        a5) * x2 + a4) * x2 + a3) * x2 + a2) * x2 + a1);
                *ps -= s;
        }
        if (*x < 0.)
        {
                *ps = *ps - pi * cml_cos(pi **x) / cml_sin(pi **x) - 1. / *x;
        }
        return 0;
}
