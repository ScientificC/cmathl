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

double
cml_exp(double x)
{
        return (double) __cml_exp(x, 33);
}


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

double
cml_frexp(double x, int *e)
{
        union {
                double v;
                struct {
			unsigned u_mant2: 32;
			unsigned u_mant1: 20;
			unsigned u_exp: 11;
                        unsigned u_sign: 1;
                } s;
        } u;

	if (x) {
		u.v = x;
		*e = u.s.u_exp - 1022;
		u.s.u_exp = 1022;
		return u.v;
	} else {
		*e = 0;
		return 0.0;
	}
}
