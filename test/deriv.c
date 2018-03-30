#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <cml/deriv.h>
#include <cml/math.h>
#include "include/test.h"

double
_f1 (double x, void *params)
{
        (void)params;
        return cml_exp(x);
}

double
d_f1 (double x, void *params)
{
        (void)params;
        return cml_exp(x);
}

double
_f2 (double x, void *params)
{
        (void)params;
        if (x >= 0.0)
        {
                return x * cml_sqrt(x);
        }
        else
        {
                return 0.0;
        }
}

double
d_f2 (double x, void *params)
{
        (void)params;
        if (x >= 0.0)
        {
                return 1.5 * cml_sqrt(x);
        }
        else
        {
                return 0.0;
        }
}

double
_f3 (double x, void *params)
{
        (void)params;
        if (!cml_equal(x, 0.0))
        {
                return cml_sin(1/x);
        }
        else
        {
                return 0.0;
        }
}

double
d_f3 (double x, void *params)
{
        (void)params;
        if (!cml_equal(x, 0.0))
        {
                return -cml_cos(1/x)/(x * x);
        }
        else
        {
                return 0.0;
        }
}

double
_f4 (double x, void *params)
{
        (void)params;
        return cml_exp(-x * x);
}

double
d_f4 (double x, void *params)
{
        (void)params;
        return -2.0 * x * cml_exp(-x * x);
}

double
_f5 (double x, void *params)
{
        (void)params;
        return x * x;
}

double
d_f5 (double x, void *params)
{
        (void)params;
        return 2.0 * x;
}

double
_f6 (double x, void *params)
{
        (void)params;
        return 1.0/x;
}

double
d_f6 (double x, void *params)
{
        (void)params;
        return -1.0/(x * x);
}

typedef int (cml_deriv_fn)(const cml_function_t *f, double x, double h, double *res, double *abserr);

#define DERIV_TEST(deriv, f, df, x) do { \
                double result, abserr; \
                double expected = CML_FN_EVAL(df, x); \
                (*deriv)(f, x, 1e-5, &result, &abserr); \
                EXPECT_NEAR(result, expected, 1e-5); \
} while (0);

int
run_deriv_tests()
{
        CATEGORY_BEGIN(Deriv)
        {
                TEST_BEGIN(Deriv)
                {
                        cml_function_t F1, DF1, F2, DF2, F3, DF3, F4, DF4, F5, DF5, F6, DF6;

                        F1.function = &_f1;
                        DF1.function = &d_f1;

                        F2.function = &_f2;
                        DF2.function = &d_f2;

                        F3.function = &_f3;
                        DF3.function = &d_f3;

                        F4.function = &_f4;
                        DF4.function = &d_f4;

                        F5.function = &_f5;
                        DF5.function = &d_f5;

                        F6.function = &_f6;
                        DF6.function = &d_f6;

                        DERIV_TEST(&cml_deriv_central, &F1, &DF1, 1.0);
                        DERIV_TEST(&cml_deriv_forward, &F1, &DF1, 1.0);
                        DERIV_TEST(&cml_deriv_backward, &F1, &DF1, 1.0);

                        DERIV_TEST(&cml_deriv_central, &F2, &DF2, 0.1);
                        DERIV_TEST(&cml_deriv_forward, &F2, &DF2, 0.1);
                        DERIV_TEST(&cml_deriv_backward, &F2, &DF2, 0.1);

                        DERIV_TEST(&cml_deriv_central, &F3, &DF3, 0.45);
                        DERIV_TEST(&cml_deriv_forward, &F3, &DF3, 0.45);
                        DERIV_TEST(&cml_deriv_backward, &F3, &DF3, 0.45);

                        DERIV_TEST(&cml_deriv_central, &F4, &DF4, 0.5);
                        DERIV_TEST(&cml_deriv_forward, &F4, &DF4, 0.5);
                        DERIV_TEST(&cml_deriv_backward, &F4, &DF4, 0.5);

                        DERIV_TEST(&cml_deriv_central, &F5, &DF5, 0.0);
                        DERIV_TEST(&cml_deriv_forward, &F5, &DF5, 0.0);
                        DERIV_TEST(&cml_deriv_backward, &F5, &DF5, 0.0);

                        DERIV_TEST(&cml_deriv_central, &F6, &DF6, 10.0);
                        DERIV_TEST(&cml_deriv_forward, &F6, &DF6, 10.0);
                        DERIV_TEST(&cml_deriv_backward, &F6, &DF6, 10.0);
                }
                TEST_END()
        }
        CATEGORY_END()

        return 0;
}
