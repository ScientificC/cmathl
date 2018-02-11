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
                        const float trigAbsError = 0.000001;

                        EXPECT_NEAR(sin(0.0), 0.0, trigAbsError);
                        EXPECT_NEAR(sin(M_PI / 2), 1.0, trigAbsError);
                        EXPECT_NEAR(sin(M_PI), 0.0, trigAbsError);
                        EXPECT_NEAR(sin(3 * M_PI / 2), -1.0, trigAbsError);
                        EXPECT_NEAR(sin(-M_PI / 2), -1.0, trigAbsError);
                        EXPECT_NEAR(sin(1578901387.78992), -0.134176, trigAbsError);

                        EXPECT_NEAR(cos(0.0), 1.0, trigAbsError);
                        EXPECT_NEAR(cos(M_PI / 2), 0.0, trigAbsError);
                        EXPECT_NEAR(cos(M_PI), -1.0, trigAbsError);
                        EXPECT_NEAR(cos(3 * M_PI / 2), 0.0, trigAbsError);
                        EXPECT_NEAR(cos(-M_PI), -1.0, trigAbsError);

                        EXPECT_NEAR(tan(0.0), 0.0, trigAbsError);
                        EXPECT_NEAR(tan(M_PI / 4), 1.0, trigAbsError);
                        EXPECT_NEAR(tan(3 * M_PI / 4), -1.0, trigAbsError);
                        EXPECT_NEAR(tan(M_PI), 0.0, trigAbsError);
                        EXPECT_NEAR(tan(-M_PI / 4), -1.0, trigAbsError);

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
                        EXPECT_FLOAT_EQ(ease_back_in(0.0), 0.0);
                        EXPECT_FLOAT_EQ(ease_back_in(1.0), 1.0);
                        EXPECT_FLOAT_EQ(ease_back_out(0.0), 0.0);
                        EXPECT_FLOAT_EQ(ease_back_out(1.0), 1.0);
                        EXPECT_FLOAT_EQ(ease_back_in_out(0.0), 0.0);
                        EXPECT_FLOAT_EQ(ease_back_in_out(1.0), 1.0);
                }
                TEST_END()

                TEST_BEGIN(Bounce)
                {
                        EXPECT_FLOAT_EQ(ease_bounce_in(0.0), 0.0);
                        EXPECT_FLOAT_EQ(ease_bounce_in(1.0), 1.0);
                        EXPECT_FLOAT_EQ(ease_bounce_out(0.0), 0.0);
                        EXPECT_FLOAT_EQ(ease_bounce_out(1.0), 1.0);
                        EXPECT_FLOAT_EQ(ease_bounce_in_out(0.0), 0.0);
                        EXPECT_FLOAT_EQ(ease_bounce_in_out(1.0), 1.0);
                }
                TEST_END()

                TEST_BEGIN(Circular)
                {
                        EXPECT_FLOAT_EQ(ease_circular_in(0.0), 0.0);
                        EXPECT_FLOAT_EQ(ease_circular_in(1.0), 1.0);
                        EXPECT_FLOAT_EQ(ease_circular_out(0.0), 0.0);
                        EXPECT_FLOAT_EQ(ease_circular_out(1.0), 1.0);
                        EXPECT_FLOAT_EQ(ease_circular_in_out(0.0), 0.0);
                        EXPECT_FLOAT_EQ(ease_circular_in_out(1.0), 1.0);

                        EXPECT_NEAR(ease_circular_in(0.0), 0.000000, 1e-5);
                        EXPECT_NEAR(ease_circular_in(0.1), 0.005013, 1e-5);
                        EXPECT_NEAR(ease_circular_in(0.2), 0.020204, 1e-5);
                        EXPECT_NEAR(ease_circular_in(0.3), 0.046061, 1e-5);
                        EXPECT_NEAR(ease_circular_in(0.4), 0.083485, 1e-5);
                        EXPECT_NEAR(ease_circular_in(0.5), 0.133975, 1e-5);
                        EXPECT_NEAR(ease_circular_in(0.6), 0.200000, 1e-5);
                        EXPECT_NEAR(ease_circular_in(0.7), 0.285857, 1e-5);
                        EXPECT_NEAR(ease_circular_in(0.8), 0.400000, 1e-5);
                        EXPECT_NEAR(ease_circular_in(0.9), 0.564110, 1e-5);
                        EXPECT_NEAR(ease_circular_in(1.0), 1.000000, 1e-5);
                }
                TEST_END()

                TEST_BEGIN(Cubic)
                {
                        EXPECT_FLOAT_EQ(ease_cubic_in(0.0), 0.0);
                        EXPECT_FLOAT_EQ(ease_cubic_in(1.0), 1.0);
                        EXPECT_FLOAT_EQ(ease_cubic_out(0.0), 0.0);
                        EXPECT_FLOAT_EQ(ease_cubic_out(1.0), 1.0);
                        EXPECT_FLOAT_EQ(ease_cubic_in_out(0.0), 0.0);
                        EXPECT_FLOAT_EQ(ease_cubic_in_out(1.0), 1.0);

                        EXPECT_FLOAT_EQ(ease_cubic_in(0.0), 0.000);
                        EXPECT_FLOAT_EQ(ease_cubic_in(0.1), 0.001);
                        EXPECT_FLOAT_EQ(ease_cubic_in(0.2), 0.008);
                        EXPECT_FLOAT_EQ(ease_cubic_in(0.3), 0.027);
                        EXPECT_FLOAT_EQ(ease_cubic_in(0.4), 0.064);
                        EXPECT_FLOAT_EQ(ease_cubic_in(0.5), 0.125);
                        EXPECT_FLOAT_EQ(ease_cubic_in(0.6), 0.216);
                        EXPECT_FLOAT_EQ(ease_cubic_in(0.7), 0.343);
                        EXPECT_FLOAT_EQ(ease_cubic_in(0.8), 0.512);
                        EXPECT_FLOAT_EQ(ease_cubic_in(0.9), 0.729);
                        EXPECT_FLOAT_EQ(ease_cubic_in(1.0), 1.000);
                }
                TEST_END()

                TEST_BEGIN(Elastic)
                {

                }
                TEST_END()

                TEST_BEGIN(Linear)
                {
                        EXPECT_FLOAT_EQ(linear_interpolation(0.0), 0.0);
                        EXPECT_FLOAT_EQ(linear_interpolation(0.1), 0.1);
                        EXPECT_FLOAT_EQ(linear_interpolation(0.2), 0.2);
                        EXPECT_FLOAT_EQ(linear_interpolation(0.3), 0.3);
                        EXPECT_FLOAT_EQ(linear_interpolation(0.4), 0.4);
                        EXPECT_FLOAT_EQ(linear_interpolation(0.5), 0.5);
                        EXPECT_FLOAT_EQ(linear_interpolation(0.6), 0.6);
                        EXPECT_FLOAT_EQ(linear_interpolation(0.7), 0.7);
                        EXPECT_FLOAT_EQ(linear_interpolation(0.8), 0.8);
                        EXPECT_FLOAT_EQ(linear_interpolation(0.9), 0.9);
                        EXPECT_FLOAT_EQ(linear_interpolation(1.0), 1.0);
                }
                TEST_END()

                TEST_BEGIN(Quadratic)
                {

                        EXPECT_FLOAT_EQ(ease_quadratic_in(0.0), 0.00);
                        EXPECT_FLOAT_EQ(ease_quadratic_in(0.1), 0.01);
                        EXPECT_FLOAT_EQ(ease_quadratic_in(0.2), 0.04);
                        EXPECT_FLOAT_EQ(ease_quadratic_in(0.3), 0.09);
                        EXPECT_FLOAT_EQ(ease_quadratic_in(0.4), 0.16);
                        EXPECT_FLOAT_EQ(ease_quadratic_in(0.5), 0.25);
                        EXPECT_FLOAT_EQ(ease_quadratic_in(0.6), 0.36);
                        EXPECT_FLOAT_EQ(ease_quadratic_in(0.7), 0.49);
                        EXPECT_FLOAT_EQ(ease_quadratic_in(0.8), 0.64);
                        EXPECT_FLOAT_EQ(ease_quadratic_in(0.9), 0.81);
                        EXPECT_FLOAT_EQ(ease_quadratic_in(1.0), 1.00);
                }
                TEST_END()

                TEST_BEGIN(Sine)
                {
                        EXPECT_NEAR(ease_sine_in(0.0), 0.000000, 1e-5);
                        EXPECT_NEAR(ease_sine_in(0.1), 0.012312, 1e-5);
                        EXPECT_NEAR(ease_sine_in(0.2), 0.048943, 1e-5);
                        EXPECT_NEAR(ease_sine_in(0.3), 0.108993, 1e-5);
                        EXPECT_NEAR(ease_sine_in(0.4), 0.190983, 1e-5);
                        EXPECT_NEAR(ease_sine_in(0.5), 0.292893, 1e-5);
                        EXPECT_NEAR(ease_sine_in(0.6), 0.412215, 1e-5);
                        EXPECT_NEAR(ease_sine_in(0.7), 0.546010, 1e-5);
                        EXPECT_NEAR(ease_sine_in(0.8), 0.690983, 1e-5);
                        EXPECT_NEAR(ease_sine_in(0.9), 0.843566, 1e-5);
                        EXPECT_NEAR(ease_sine_in(1.0), 1.000000, 1e-5);
                }
                TEST_END()
        }
        CATEGORY_END()
        #endif

        #ifndef CML_NO_STRUCTURES
        CATEGORY_BEGIN(Quaternion)
        {
                TEST_BEGIN(Identity)
                {
                        quaternion_t q = quaternion_identity();

                        EXPECT_FLOAT_EQ(q.w, 1.0);
                        EXPECT_FLOAT_EQ(q.x, 0.0);
                        EXPECT_FLOAT_EQ(q.y, 0.0);
                        EXPECT_FLOAT_EQ(q.z, 0.0);
                        EXPECT_FLOAT_EQ(quaternion_norm(q), 1.0);
                        EXPECT_FLOAT_EQ(quaternion_abs(q), 1.0);
                }
                TEST_END()

                TEST_BEGIN(Conjugate)
                {
                        quaternion_t qA = quaternion_from_axis_anglef3(M_TAU / 4.0, 1.0, 1.0, 1.0),
                                     qB = quaternion_from_axis_anglef3(M_TAU / 4.0, -1.0, -1.0, -1.0);

                        EXPECT_TRUE(quaternion_equal(qA, quaternion_conj(qB)));
                }
                TEST_END()
        }
        CATEGORY_END()
        #endif

        return 0;
}
