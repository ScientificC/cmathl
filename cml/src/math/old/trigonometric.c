#include <stdlib.h>
#include <cml/math.h>


/*
 * Computes real arc cosine
 *
 * @param double x
 * @return double
 */

double
cml_acos(double x)
{
        double y;

        y = cml_asin(x);

        return M_PI_2 - y;
}


/*
 * Computes real arc sine
 * --| asin(x) = atan(x / sqrt(1 − x²))
 *
 * @param double x
 * @return double
 */

double
cml_asin(double x)
{
        double y, z, w, k;

        y = x*x;
        z = 1.0 - y;
        w = cml_sqrt(z);
        k = x/w;

        return cml_atan(k);
}


/*
 * Computes real cotangent
 *
 * @param double x
 * @return double
 */

double
cml_cot(double x)
{
        double y;

        y = cml_sin(x);

        if (cml_isnull(y))
        {
                return cml_nan();
        }

        return cml_cos(x) / y;
}


/*
 * Computes real cosecant
 *
 * @param double x
 * @return double
 */

double
cml_csc(double x)
{
        double y;

        y = cml_sin(x);
        return cml_inverse(y);
}


/*
 * Computes real secant function by using trigonometric identities
 *
 * @param double x
 * @return double
 */

double
cml_sec(double x)
{
        double y;

        y = cml_cos(x);
        return cml_inverse(y);
}

/*
 * Computes real tangent
 * --| tan(x) = sin(x) / cos(x)
 *
 * @param double x
 * @return double
 */

double
cml_tan(double x)
{
        double y;

        y = cml_cos(x);

        if (cml_isnull(y))
        {
                return cml_nan();
        }

        return cml_sin(x) / y;
}
