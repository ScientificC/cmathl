#include <stdlib.h>
#include <stdio.h>
#include <cml/errno.h>
#include <cml/math.h>
#include <cml/roots.h>
#include "include/test.h"

static double epsabs = 0.0001;
static double epsrel = 0.00001;
static int n_max = 1000;

#define FUNC  f_cos
#define FDF_FUNC fdf_cos

static double
f_cos(double x, void *p)
{
        (void) p;
        return cml_cos(x);
}


static void
fdf_cos(double x, void *p, double *f, double *df)
{
        (void) p;

        *f = cml_cos(x);
        *df = -cml_sin(x);
}


int
run_roots_tests()
{
        CATEGORY_BEGIN(Roots)
        {
                TEST_BEGIN(Bisection Method)
                {
                        double x1, x2, r;
                        cml_function_t func;

                        x1 = 0;
                        x2 = 3;
                        func.function = FUNC;
                        func.params = NULL;

                        cml_root_bisection(&func, x1, x2, epsrel, epsabs, n_max, &r);
                        EXPECT_NEAR(r, M_PI_2, epsabs);
                }
                TEST_END()

                TEST_BEGIN(Newton Method)
                {
                        double x0, r;
                        cml_function_fdf_t func;

                        x0 = 0.5;
                        func.fdf = FDF_FUNC;
                        func.params = NULL;

                        cml_root_newton(&func, x0, epsrel, epsabs, n_max, &r);
                        EXPECT_NEAR(r, M_PI_2, epsabs);
                }
                TEST_END()
        }
        CATEGORY_END()

        return 0;
}
