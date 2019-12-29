#include <stdlib.h>
#include <cml/math.h>


double
cml_ldexp(double x, int e)
{
        int ex;

        if (cml_isnull(x))
        {
                return x;
        }
        else
        {
                long double y = cml_frexp(x, &ex);
                long double e2 = e + ex, p2;

                if (e2 >= DBL_MAX_EXP)
                {
                        y *= cml_pow(2.0, e2 - DBL_MAX_EXP + 1);
                        e2 = DBL_MAX_EXP - 1;
                }
                else if (e2 <= DBL_MIN_EXP)
                {
                        y *= cml_pow(2.0, e2 - DBL_MIN_EXP - 1);
                        e2 = DBL_MIN_EXP + 1;
                }

                p2 = cml_pow(2.0, e2);

                return y * p2;
        }
}