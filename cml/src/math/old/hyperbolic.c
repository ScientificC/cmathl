#include <stdlib.h>
#undef CML_NO_ALIASES
#define CML_NO_ALIASES
#include <cml/math.h>


/*
 * Computes real hyperbolic arc cosine
 * --| acosh(x) = log(x + sqrt(x² - 1))
 *
 * @param double x
 * @return double
 */

double
cml_acosh(double x)
{
        double y, z, w, k;

        y = x*x;
        z = y - 1.0;
        w = cml_sqrt(z);
        k = x + w;

        return cml_log(k);
}


/*
 * Computes real hyperbolic arc sine
 * --| asinh(x) = log(x + sqrt(x² + 1))
 *
 * @param double x
 * @return double
 */

double
cml_asinh(double x)
{
        double y, z, w, k;

        y = x*x;
        z = y + 1.0;
        w = cml_sqrt(z);
        k = x + w;

        return cml_log(k);
}


/*
 * Computes real hyperbolic cosine
 * --| cosh(x) = 1/2 * (exp(x) + exp(−x))
 *
 * @param double x
 * @return double
 */

double
cml_cosh(double x)
{
        double y, z, w, k;

        y = -x;
        z = cml_exp(x);
        w = cml_exp(y);
        k = z + w;

        return k / 2.0;
}


/*
 * Computes real hyperbolic cotangent
 *
 * @param double x
 * @return double
 */

double
cml_coth(double x)
{
        double y, z, w;

        y = cml_cosh(x);
        z = cml_sinh(x);
        w = cml_inverse(z);

        return y*w;
}


/*
 * Computes real hyperbolic cosecant
 *
 * @param double x
 * @return double
 */

double
cml_csch(double x)
{
        double y, h;

        y = cml_sinh(x);
        h = cml_inverse(y);

        return h;
}


/*
 * Computes real hyperbolic secant function by using Euler relationships
 *
 * @param double x
 * @return double
 */

double
cml_sech(double x)
{
        double y, h;

        y = cml_cosh(x);
        h = cml_inverse(y);

        return h;
}


/*
 * Computes real hyperbolic sine
 * --| sinh(x) = 1/2 * (exp(x) − exp(−x))
 *
 * @param double x
 * @return double
 */

double
cml_sinh(double x)
{
        double y, z, w, k;

        y = -x;
        z = cml_exp(x);
        w = cml_exp(y);
        k = z - w;

        return k/2.0;
}


/*
 * Computes real hyperbolic tangent
 * --| tanh(x) = sinh(x) / cosh(x)
 *
 * @param double x
 * @return double
 */

double
cml_tanh(double x)
{
        double y, z, w;

        y = cml_sinh(x);
        z = cml_cosh(x);
        w = cml_inverse(z);

        return y*w;
}
