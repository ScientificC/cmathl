#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <cml/diff.h>
#include <cml/math.h>
#include "include/test.h"

double
f1 (double x, void *params)
{
        (void)params;
        return real_exp(x);
}

double
df1 (double x, void *params)
{
        (void)params;
        return real_exp(x);
}

double
f2 (double x, void *params)
{
        (void)params;
        if (x >= 0.0)
        {
                return x * real_sqrt(x);
        }
        else
        {
                return 0.0;
        }
}

double
df2 (double x, void *params)
{
        (void)params;
        if (x >= 0.0)
        {
                return 1.5 * real_sqrt(x);
        }
        else
        {
                return 0.0;
        }
}

double
f3 (double x, void *params)
{
        (void)params;
        if (!real_equal(x, 0.0))
        {
                return real_sin(1/x);
        }
        else
        {
                return 0.0;
        }
}

double
df3 (double x, void *params)
{
        (void)params;
        if (!real_equal(x, 0.0))
        {
                return -real_cos(1/x)/(x * x);
        }
        else
        {
                return 0.0;
        }
}

double
f4 (double x, void *params)
{
        (void)params;
        return real_exp(-x * x);
}

double
df4 (double x, void *params)
{
        (void)params;
        return -2.0 * x * real_exp(-x * x);
}

double
f5 (double x, void *params)
{
        (void)params;
        return x * x;
}

double
df5 (double x, void *params)
{
        (void)params;
        return 2.0 * x;
}

double
f6 (double x, void *params)
{
        (void)params;
        return 1.0/x;
}

double
df6 (double x, void *params)
{
        (void)params;
        return -1.0/(x * x);
}

typedef int (diff_fn)(const function_t *f, double x, double *res, double *abserr);

#define DIFF_TEST(diff, f, df, x) do { \
                double result, abserr; \
                double expected = FN_EVAL(df, x); \
                (*diff)(f, x, &result, &abserr); \
                EXPECT_NEAR(result, expected, 1e-6); \
} while (0);

#define DIFF_NEAR_TEST(diff, f, df, x, err) do { \
                double result, abserr; \
                double expected = FN_EVAL(df, x); \
                (*diff)(f, x, &result, &abserr); \
                EXPECT_NEAR(result, expected, err); \
} while (0);

int
run_diff_tests()
{
        CATEGORY_BEGIN(Diff)
        {
                TEST_BEGIN(Diff)
                {
                        function_t F1, DF1, F2, DF2, F3, DF3, F4, DF4, F5, DF5, F6, DF6;

                        F1.function = &f1;
                        DF1.function = &df1;

                        F2.function = &f2;
                        DF2.function = &df2;

                        F3.function = &f3;
                        DF3.function = &df3;

                        F4.function = &f4;
                        DF4.function = &df4;

                        F5.function = &f5;
                        DF5.function = &df5;

                        F6.function = &f6;
                        DF6.function = &df6;

                        DIFF_TEST(&diff_central, &F1, &DF1, 1.0);
                        DIFF_NEAR_TEST(&diff_forward, &F1, &DF1, 1.0, 0.1f);
                        DIFF_TEST(&diff_backward, &F1, &DF1, 1.0);

                        DIFF_NEAR_TEST(&diff_central, &F2, &DF2, 0.1, 1e-3f);
                        DIFF_NEAR_TEST(&diff_forward, &F2, &DF2, 0.1, 0.1f);
                        DIFF_TEST(&diff_backward, &F2, &DF2, 0.1);

                        /* DIFF_NEAR_TEST(&diff_central, &F3, &DF3, 0.45, 0.1f); */
                        DIFF_TEST(&diff_forward, &F3, &DF3, 0.45);
                        DIFF_TEST(&diff_backward, &F3, &DF3, 0.45);

                        DIFF_NEAR_TEST(&diff_central, &F4, &DF4, 0.5, 0.1f);
                        DIFF_TEST(&diff_forward, &F4, &DF4, 0.5);
                        DIFF_TEST(&diff_backward, &F4, &DF4, 0.5);

                        DIFF_TEST(&diff_central, &F5, &DF5, 0.0);
                        DIFF_TEST(&diff_forward, &F5, &DF5, 0.0);
                        DIFF_TEST(&diff_backward, &F5, &DF5, 0.0);

                        DIFF_NEAR_TEST(&diff_central, &F6, &DF6, 10.0, 1e-3f);
                        DIFF_TEST(&diff_forward, &F6, &DF6, 10.0);
                        DIFF_TEST(&diff_backward, &F6, &DF6, 10.0);
                }
                TEST_END()
        }
        CATEGORY_END()

        return 0;
}
