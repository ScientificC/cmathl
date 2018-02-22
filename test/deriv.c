#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <cml.h>
#include "include/test.h"

real_t
_f1 (real_t x, void *params)
{
        (void)params;
        return real_exp(x);
}

real_t
d_f1 (real_t x, void *params)
{
        (void)params;
        return real_exp(x);
}

real_t
_f2 (real_t x, void *params)
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
d_f2 (real_t x, void *params)
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
_f3 (real_t x, void *params)
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
d_f3 (real_t x, void *params)
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
_f4 (real_t x, void *params)
{
        (void)params;
        return real_exp(-x * x);
}

real_t
d_f4 (real_t x, void *params)
{
        (void)params;
        return -2.0 * x * real_exp(-x * x);
}

real_t
_f5 (real_t x, void *params)
{
        (void)params;
        return x * x;
}

real_t
d_f5 (real_t x, void *params)
{
        (void)params;
        return 2.0 * x;
}

real_t
_f6 (real_t x, void *params)
{
        (void)params;
        return 1.0/x;
}

real_t
d_f6 (real_t x, void *params)
{
        (void)params;
        return -1.0/(x * x);
}

typedef int (deriv_fn)(const function_t *f, real_t x, real_t h, real_t *res, real_t *abserr);

#define DERIV_TEST(deriv, f, df, x) do { \
                real_t result, abserr; \
                real_t expected = FN_EVAL(df, x); \
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
                        function_t F1, DF1, F2, DF2, F3, DF3, F4, DF4, F5, DF5, F6, DF6;

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

                        DERIV_TEST(&deriv_central, &F1, &DF1, 1.0);
                        DERIV_TEST(&deriv_forward, &F1, &DF1, 1.0);
                        DERIV_TEST(&deriv_backward, &F1, &DF1, 1.0);

                        DERIV_TEST(&deriv_central, &F2, &DF2, 0.1);
                        DERIV_TEST(&deriv_forward, &F2, &DF2, 0.1);
                        DERIV_TEST(&deriv_backward, &F2, &DF2, 0.1);

                        DERIV_TEST(&deriv_central, &F3, &DF3, 0.45);
                        DERIV_TEST(&deriv_forward, &F3, &DF3, 0.45);
                        DERIV_TEST(&deriv_backward, &F3, &DF3, 0.45);

                        DERIV_TEST(&deriv_central, &F4, &DF4, 0.5);
                        DERIV_TEST(&deriv_forward, &F4, &DF4, 0.5);
                        DERIV_TEST(&deriv_backward, &F4, &DF4, 0.5);

                        DERIV_TEST(&deriv_central, &F5, &DF5, 0.0);
                        DERIV_TEST(&deriv_forward, &F5, &DF5, 0.0);
                        DERIV_TEST(&deriv_backward, &F5, &DF5, 0.0);

                        DERIV_TEST(&deriv_central, &F6, &DF6, 10.0);
                        DERIV_TEST(&deriv_forward, &F6, &DF6, 10.0);
                        DERIV_TEST(&deriv_backward, &F6, &DF6, 10.0);
                }
                TEST_END()
        }
        CATEGORY_END()

        return 0;
}
