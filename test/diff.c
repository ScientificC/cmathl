#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <cml.h>
#include "include/test.h"

real_t
f1 (real_t x, void *params)
{
        (void)params;
        return real_exp(x);
}

real_t
df1 (real_t x, void *params)
{
        (void)params;
        return real_exp(x);
}

real_t
f2 (real_t x, void *params)
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

real_t
df2 (real_t x, void *params)
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

real_t
f3 (real_t x, void *params)
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

real_t
df3 (real_t x, void *params)
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

real_t
f4 (real_t x, void *params)
{
        (void)params;
        return real_exp(-x * x);
}

real_t
df4 (real_t x, void *params)
{
        (void)params;
        return -2.0 * x * real_exp(-x * x);
}

real_t
f5 (real_t x, void *params)
{
        (void)params;
        return x * x;
}

real_t
df5 (real_t x, void *params)
{
        (void)params;
        return 2.0 * x;
}

real_t
f6 (real_t x, void *params)
{
        (void)params;
        return 1.0/x;
}

real_t
df6 (real_t x, void *params)
{
        (void)params;
        return -1.0/(x * x);
}

typedef int (diff_fn)(const function_t *f, real_t x, real_t *res, real_t *abserr);

#define DIFF_TEST(diff, f, df, x) do { \
                real_t result, abserr; \
                real_t expected = FN_EVAL(df, x); \
                (*diff)(f, x, &result, &abserr); \
                EXPECT_NEAR(result, expected, 0.1f); \
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
                        DIFF_TEST(&diff_forward, &F1, &DF1, 1.0);
                        DIFF_TEST(&diff_backward, &F1, &DF1, 1.0);

                        DIFF_TEST(&diff_central, &F2, &DF2, 0.1);
                        DIFF_TEST(&diff_forward, &F2, &DF2, 0.1);
                        DIFF_TEST(&diff_backward, &F2, &DF2, 0.1);

                        DIFF_TEST(&diff_central, &F3, &DF3, 0.45);
                        DIFF_TEST(&diff_forward, &F3, &DF3, 0.45);
                        DIFF_TEST(&diff_backward, &F3, &DF3, 0.45);

                        DIFF_TEST(&diff_central, &F4, &DF4, 0.5);
                        DIFF_TEST(&diff_forward, &F4, &DF4, 0.5);
                        DIFF_TEST(&diff_backward, &F4, &DF4, 0.5);

                        DIFF_TEST(&diff_central, &F5, &DF5, 0.0);
                        DIFF_TEST(&diff_forward, &F5, &DF5, 0.0);
                        DIFF_TEST(&diff_backward, &F5, &DF5, 0.0);

                        DIFF_TEST(&diff_central, &F6, &DF6, 10.0);
                        DIFF_TEST(&diff_forward, &F6, &DF6, 10.0);
                        DIFF_TEST(&diff_backward, &F6, &DF6, 10.0);
                }
                TEST_END()
        }
        CATEGORY_END()

        return 0;
}
