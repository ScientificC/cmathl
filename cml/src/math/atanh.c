#include <stdlib.h>
#include <scic/errno.h>
#include <cml/math.h>

/**
 * Inverse hyperbolic tangent
 * 
 * Returns inverse hyperbolic tangent of argument in the range
 * MINLOG to MAXLOG.
 *
 * If |x| < 0.5, the rational form x + x**3 P(x)/Q(x) is
 * employed. Otherwise,
 *        atanh(x) = 0.5 * log((1 + x) / (1 - x)).
 * 
 */

extern double cml_polevl(double, void *, int);
extern double cml_p1evl(double, void *, int);

static double P[] = {
        -8.54074331929669305196E-1,
        1.20426861384072379242E1,
        -4.61252884198732692637E1,
        6.54566728676544377376E1,
        -3.09092539379866942570E1
};

static double Q[] = {
        /* 1.00000000000000000000E0,*/
        -1.95638849376911654834E1,
        1.08938092147140262656E2,
        -2.49839401325893582852E2,
        2.52006675691344555838E2,
        -9.27277618139601130017E1
};


double
cml_atanh(double x)
{
        double s, z;

        if (cml_isnull(x))
	        return x;

        z = cml_abs(x);

        if (z >= 1.0)
	{
                if (x == 1.0)
                        return CML_POSINF;

                if (x == -1.0)
                        return CML_NEGINF;

                SCIC_ERROR_VAL("atanh", SCIC_EDOM, CML_NAN);
	}

        if (z < 1.0e-7)
                return x;

        if (z < 0.5)
	{
                z = x * x;
                s = x + x * z * (cml_polevl(z, P, 4) / cml_p1evl(z, Q, 5));
                
                return s;
	}

        return 0.5 * cml_log((1.0 + x) / (1.0 - x));
}
