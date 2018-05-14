#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <cml/math.h>
#include "include/test.h"

int cml_count_tests = 0;
int cml_count_failedtests = 0;
int cml_count_failures = 0;

int
run_real_tests()
{
        CATEGORY_BEGIN(Macros)
        {
                TEST_BEGIN(Math)
                {
                        EXPECT_FLOAT_EQ(CML_NAN, 0.0/0.0);
                        EXPECT_FLOAT_EQ(CML_POSINF, CML_POSINF);
                        EXPECT_FLOAT_EQ(CML_NEGINF, -CML_POSINF);
                }
                TEST_END()
        }
        CATEGORY_END()

        CATEGORY_BEGIN(Real)
        {
                TEST_BEGIN(Initialization)
                {
                        double x = 1.0;
                        EXPECT_FLOAT_EQ(x, 1.0);
                        printf(" Size of double: %ld  ", sizeof(double));
                }
                TEST_END()

                TEST_BEGIN(Trigonometry)
                {
                        /* We have to be a little looser with our equality constraint
                           because of floating-point precision issues. */
                        EXPECT_FLOAT_EQ(cml_sin(0.0), 0.0);
                        EXPECT_FLOAT_EQ(cml_sin(M_PI / 2), 1.0);
                        EXPECT_FLOAT_EQ(cml_sin(M_PI), 0.0);
                        EXPECT_FLOAT_EQ(cml_sin(3 * M_PI / 2), -1.0);
                        EXPECT_FLOAT_EQ(cml_sin(-M_PI / 2), -1.0);

                        EXPECT_FLOAT_EQ(cml_cos(0.0), 1.0);
                        EXPECT_FLOAT_EQ(cml_cos(M_PI / 2), 0.0);
                        EXPECT_FLOAT_EQ(cml_cos(M_PI), -1.0);
                        EXPECT_FLOAT_EQ(cml_cos(3 * M_PI / 2), 0.0);
                        EXPECT_FLOAT_EQ(cml_cos(-M_PI), -1.0);

                        EXPECT_FLOAT_EQ(cml_tan(0.0), 0.0);
                        EXPECT_FLOAT_EQ(cml_tan(M_PI / 4), 1.0);
                        EXPECT_FLOAT_EQ(cml_tan(3 * M_PI / 4), -1.0);
                        EXPECT_FLOAT_EQ(cml_tan(M_PI), 0.0);
                        EXPECT_FLOAT_EQ(cml_tan(-M_PI / 4), -1.0);

                        EXPECT_FLOAT_EQ(cml_atan(0.0), 0.0);
                        EXPECT_FLOAT_EQ(cml_atan(1.0), M_PI / 4);
                        EXPECT_FLOAT_EQ(cml_atan(-1.0), -M_PI / 4);

                        /* This isn't the most rigorous because we're really just sanity-
                           checking that things work by default. */
                }
                TEST_END()

                TEST_BEGIN(Hyperbolic)
                {
                        EXPECT_FLOAT_EQ(cml_atanh(0.5), 0.5493061443340548);
                        EXPECT_FLOAT_EQ(cml_atanh(0.75), 0.9729550745276566);
                }
                TEST_END()

                TEST_BEGIN(SquareRoot)
                {
                        EXPECT_FLOAT_EQ(cml_sqrt(16.0), 4.0);
                        EXPECT_FLOAT_EQ(cml_sqrt(10.0), 3.16227766017);
                }
                TEST_END()

                TEST_BEGIN(Power)
                {
                        EXPECT_FLOAT_EQ(cml_pow(2.0, 0), 1.0);
                        EXPECT_FLOAT_EQ(cml_pow(2.0, 4), 16.0);
                        EXPECT_FLOAT_EQ(cml_pow(2.0, -2), 0.25);
                        EXPECT_FLOAT_EQ(cml_pow(2.0, -2.5), 0.17677669529);
                        EXPECT_FLOAT_EQ(cml_pow(2.0, 4.1), 17.1483754006);
                }
                TEST_END()
        }
        CATEGORY_END()

        return 0;
}

int
main()
{
        clock_t cl = clock();

        run_real_tests();

        (cml_count_failedtests > 0) ?
        printf(RED) :
        printf(GREEN);

        printf("\n%d/%d tests passed overall, %d failures\n" RESET "%Lg%s\n",
               cml_count_tests - cml_count_failedtests,
               cml_count_tests,
               cml_count_failures,
               (long double) (clock()-cl)/CLOCKS_PER_SEC,
               "s"
               );

        return (cml_count_failedtests > 0);
}
