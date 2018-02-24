#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <cml/easings.h>
#include <cml/math.h>
#include "include/test.h"


int
run_easings_tests()
{
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

                        EXPECT_NEAR(ease_circular_in(0.0), 0.000000, 1e-6);
                        EXPECT_NEAR(ease_circular_in(0.1), 0.005013, 1e-6);
                        EXPECT_NEAR(ease_circular_in(0.2), 0.020204, 1e-6);
                        EXPECT_NEAR(ease_circular_in(0.3), 0.046061, 1e-6);
                        EXPECT_NEAR(ease_circular_in(0.4), 0.083485, 1e-6);
                        EXPECT_NEAR(ease_circular_in(0.5), 0.133975, 1e-6);
                        EXPECT_NEAR(ease_circular_in(0.6), 0.200000, 1e-6);
                        EXPECT_NEAR(ease_circular_in(0.7), 0.285857, 1e-6);
                        EXPECT_NEAR(ease_circular_in(0.8), 0.400000, 1e-6);
                        EXPECT_NEAR(ease_circular_in(0.9), 0.564110, 1e-6);
                        EXPECT_NEAR(ease_circular_in(1.0), 1.000000, 1e-6);
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
                        EXPECT_NEAR(ease_sine_in(0.0), 0.000000, 1e-6);
                        EXPECT_NEAR(ease_sine_in(0.1), 0.012312, 1e-6);
                        EXPECT_NEAR(ease_sine_in(0.2), 0.048943, 1e-6);
                        EXPECT_NEAR(ease_sine_in(0.3), 0.108993, 1e-6);
                        EXPECT_NEAR(ease_sine_in(0.4), 0.190983, 1e-6);
                        EXPECT_NEAR(ease_sine_in(0.5), 0.292893, 1e-6);
                        EXPECT_NEAR(ease_sine_in(0.6), 0.412215, 1e-6);
                        EXPECT_NEAR(ease_sine_in(0.7), 0.546010, 1e-6);
                        EXPECT_NEAR(ease_sine_in(0.8), 0.690983, 1e-6);
                        EXPECT_NEAR(ease_sine_in(0.9), 0.843566, 1e-6);
                        EXPECT_NEAR(ease_sine_in(1.0), 1.000000, 1e-6);
                }
                TEST_END()
        }
        CATEGORY_END()

        return 0;
}
