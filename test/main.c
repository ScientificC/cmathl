#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <cml.h>
#include "include/test.h"

int run_tests();

int main()
{
        clock_t cl = clock();

        run_tests();

        if (cml_count_failedtests > 0) {
                printf(RED);
        } else {
                printf(GREEN);
        }

        printf("\n%d/%d tests passed overall, %d failures\n" RESET,
               cml_count_tests - cml_count_failedtests,
               cml_count_tests,
               cml_count_failures
               );

        printf("%Lg%s\n\n", (long double) (clock()-cl)/CLOCKS_PER_SEC, "s");

        return (cml_count_failedtests > 0);
}

int run_tests()
{
        CATEGORY_BEGIN(Macros)
        {
                TEST_BEGIN(Math)
                {
                        EXPECT_FLOAT_EQ(NAN, log(-1.0));
                        EXPECT_FLOAT_EQ(INF, INF);
                        EXPECT_FLOAT_EQ(NINF, -INF);
                }
                TEST_END()
        }
        CATEGORY_END()

        CATEGORY_BEGIN(Real)
        {
                TEST_BEGIN(Initialization)
                {
                        real_t x = 1.0;
                        EXPECT_FLOAT_EQ(x, 1.0);
                        printf(" Size of real_t: %ld  ", sizeof(real_t));
                }
                TEST_END()

                TEST_BEGIN(Trigonometry)
                {
                        /* We have to be a little looser with our equality constraint
                           because of floating-point precision issues. */
                        const float trigAbsError = 0.0001f;

                        EXPECT_NEAR(sin(0.0), 0.0, trigAbsError);
                        EXPECT_NEAR(sin(PI / 2), 1.0, trigAbsError);
                        EXPECT_NEAR(sin(PI), 0.0, trigAbsError);
                        EXPECT_NEAR(sin(3 * PI / 2), -1.0, trigAbsError);
                        EXPECT_NEAR(sin(-PI / 2), -1.0, trigAbsError);

                        EXPECT_NEAR(cos(0.0), 1.0, trigAbsError);
                        EXPECT_NEAR(cos(PI / 2), 0.0, trigAbsError);
                        EXPECT_NEAR(cos(PI), -1.0, trigAbsError);
                        EXPECT_NEAR(cos(3 * PI / 2), 0.0, trigAbsError);
                        EXPECT_NEAR(cos(-PI), -1.0, trigAbsError);

                        EXPECT_NEAR(tan(0.0), 0.0, trigAbsError);
                        EXPECT_NEAR(tan(PI / 4), 1.0, trigAbsError);
                        EXPECT_NEAR(tan(3 * PI / 4), -1.0, trigAbsError);
                        EXPECT_NEAR(tan(PI), 0.0, trigAbsError);
                        EXPECT_NEAR(tan(-PI / 4), -1.0, trigAbsError);

                        /* This isn't the most rigorous because we're really just sanity-
                           checking that things work by default. */
                }
                TEST_END()

                TEST_BEGIN(SquareRoot)
                {
                        EXPECT_FLOAT_EQ(sqrt(16.0), 4.0);
                        EXPECT_NEAR(sqrt(10.0), 3.1616211, 0.001f);
                }
                TEST_END()

                TEST_BEGIN(Power)
                {
                        EXPECT_FLOAT_EQ(pow(2.0, 0), 1.0);
                        EXPECT_FLOAT_EQ(pow(2.0, 4), 16.0);
                        EXPECT_FLOAT_EQ(pow(2.0, -2), 0.25);
                        EXPECT_NEAR(pow(2.0, 4.1), 17.148376, 0.0001f);
                        EXPECT_NEAR(pow(2.0, -2.5), 0.176777, 0.0001f);
                }
                TEST_END()
        }
        CATEGORY_END()

        CATEGORY_BEGIN(Complex)
        {
                TEST_BEGIN(Initialization)
                {
                        complex_t z = complex(1.0, 4.0);
                        EXPECT_FLOAT_EQ(creal(z), 1.0);
                        EXPECT_FLOAT_EQ(cimag(z), 4.0);
                }
                TEST_END()
        }
        CATEGORY_END()

        #ifndef CML_NO_EASING_FUNCTIONS
        CATEGORY_BEGIN(Easings)
        {
                TEST_BEGIN(Back)
                {
                        EXPECT_FLOAT_EQ(back_ease_in(0.0), 0.0);
                        EXPECT_FLOAT_EQ(back_ease_in(1.0), 1.0);
                        EXPECT_FLOAT_EQ(back_ease_out(0.0), 0.0);
                        EXPECT_FLOAT_EQ(back_ease_out(1.0), 1.0);
                        EXPECT_FLOAT_EQ(back_ease_in_out(0.0), 0.0);
                        EXPECT_FLOAT_EQ(back_ease_in_out(1.0), 1.0);
                }
                TEST_END()

                TEST_BEGIN(Bounce)
                {
                        EXPECT_FLOAT_EQ(bounce_ease_in(0.0), 0.0);
                        EXPECT_FLOAT_EQ(bounce_ease_in(1.0), 1.0);
                        EXPECT_FLOAT_EQ(bounce_ease_out(0.0), 0.0);
                        EXPECT_FLOAT_EQ(bounce_ease_out(1.0), 1.0);
                        EXPECT_FLOAT_EQ(bounce_ease_in_out(0.0), 0.0);
                        EXPECT_FLOAT_EQ(bounce_ease_in_out(1.0), 1.0);
                }
                TEST_END()

                TEST_BEGIN(Circular)
                {
                        EXPECT_FLOAT_EQ(circular_ease_in(0.0), 0.0);
                        EXPECT_FLOAT_EQ(circular_ease_in(1.0), 1.0);
                        EXPECT_FLOAT_EQ(circular_ease_out(0.0), 0.0);
                        EXPECT_FLOAT_EQ(circular_ease_out(1.0), 1.0);
                        EXPECT_FLOAT_EQ(circular_ease_in_out(0.0), 0.0);
                        EXPECT_FLOAT_EQ(circular_ease_in_out(1.0), 1.0);
                }
                TEST_END()

                TEST_BEGIN(Cubic)
                {
                        EXPECT_FLOAT_EQ(cubic_ease_in(0.0), 0.0);
                        EXPECT_FLOAT_EQ(cubic_ease_in(1.0), 1.0);
                        EXPECT_FLOAT_EQ(cubic_ease_out(0.0), 0.0);
                        EXPECT_FLOAT_EQ(cubic_ease_out(1.0), 1.0);
                        EXPECT_FLOAT_EQ(cubic_ease_in_out(0.0), 0.0);
                        EXPECT_FLOAT_EQ(cubic_ease_in_out(1.0), 1.0);
                }
                TEST_END()
        }
        CATEGORY_END()
        #endif

        return 0;
}
