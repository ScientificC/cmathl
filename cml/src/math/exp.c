#include <stdlib.h>
#include <scic/errno.h>
#undef CML_NO_ALIASES
#define CML_NO_ALIASES
#include <cml/math.h>


#ifdef CML_NO_MATH
long double
__cml_exp(long double x, int n_max)
{
        int n;
        long double term, oldsum, newsum;

        n = 0;
        oldsum = 0.0L;
        newsum = 1.0L;
        term = 1.0L;

        /* terminates when the new sum is no different from the old sum */
        for (n = 0; n < n_max;)
        {
                if (cml_equal(newsum, oldsum))
                {
                        break;
                }

                oldsum = newsum;
                n++;
                term = term*x/n; /* term has the value (x~n)/(n!) */
                newsum = newsum + term; /* approximates exp(x) */
        }

        return newsum;
}
#else
        #include <math.h>
        #define __cml_exp(x, ...) __CML_MATH_NAME(exp)(x)
#endif

/*
 * Returns e raised to the given power
 *
 * @param double x: Exponent of the function
 * @return double
 */

__CML_EXTERN_INLINE double
cml_exp(double x)
{
        return (double) __cml_exp(x, 33);
}
