#include <stdlib.h>
#include <cml/math.h>

/*
 * Computes absolute value of a floating point value
 *
 * @param double x
 * @return double
 */

double
cml_abs(double x)
{
        return x * cml_sgn(x);
}


/*
 * An angle x is reduced to the interval [0, 2pi] by subtracting a number k of
 * 2pi radians, where k is the integer division between x and 2pi
 *
 * @param double x
 * @return double
 */

double
cml_ared_a(double x, double a)
{
        return x - a * cml_div(x, a);
}

double
cml_ared(double x)
{
        return x - cml_div(x, M_TAU) * M_TAU;
}


/*
 * Computes the quotient and remainder of integer division
 *
 * @param double x
 * @param double y
 * @return double
 */

double
cml_div(double x, double y)
{
        return cml_floor(x / y);
}


double
cml_hypot(double x, double y)
{
        double xabs = cml_abs(x);
        double yabs = cml_abs(y);
        double min, max;

        /* Follow the optional behavior of the ISO C standard and return
         * +Inf when any of the argument is +-Inf, even if the other is NaN.
         * http://pubs.opengroup.org/onlinepubs/009695399/functions/hypot.html
         */
        if (cml_isinf(x) || cml_isinf(y))
        {
                return CML_POSINF;
        }

        if (xabs < yabs) {
                min = xabs;
                max = yabs;
        }
        else
        {
                min = yabs;
                max = xabs;
        }

        if (cml_isnull(min))
        {
                return max;
        }

        double u = min / max;
        return max * cml_sqrt(1 + u * u);
}


double
cml_hypot3(double x, double y, double z)
{
        double xabs = cml_abs(x);
        double yabs = cml_abs(y);
        double zabs = cml_abs(z);
        double w = CML_MAX(xabs, CML_MAX(yabs, zabs));

        if (cml_isnull(w))
        {
                return 0.0;
        }
        else
        {
                double r = w * cml_sqrt((xabs / w) * (xabs / w) +
                                        (yabs / w) * (yabs / w) +
                                        (zabs / w) * (zabs / w));
                return r;
        }
}


double
cml_inverse(double x)
{
        if (cml_isnull(x))
        {
                return cml_nan();
        }

        return 1.0 / x;
}


/*
 * remainder of the floating point division operation
 *
 * @param double x
 * @param double y
 * @return double
 */

double
cml_mod(double x, double y)
{
        return x - y * cml_div(x, y);
}


double
cml_opposite(double x)
{
        return -x;
}


double
cml_sgn(double x)
{
        return x >= 0.0 ? 
                1.0 : 
                -1.0;
}
