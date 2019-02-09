#include <stdlib.h>
#include <cml/math.h>

double
cml_expm1(double x)
{
        /* FIXME: this should be improved */

        if (cml_abs(x) < M_LN2)
        {
                /* Compute the taylor series S = x + (1/2!) x^2 + (1/3!) x^3 + ... */

                long double i = 1.0;
                long double sum = x;
                long double term = x / 1.0;

                do
                {
                        i++;
                        term *= x/i;
                        sum += term;
                } while (cml_abs(term) > cml_abs(sum) * CML_DBL_EPSILON);

                return (double) sum;
        }
        else
        {
                return cml_exp(x) - 1.0;
        }
}