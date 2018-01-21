/* Copyright (C) 2017 CMATHL

   This file is part of CML.

   CML is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   CML is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with CML. If not, see <http://www.gnu.org/licenses/>.     */


#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <GL/gl.h>
#include <cml.h>
#include "include/test.h"

int run_tests();

int main(int argc, char const *argv[])
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
        CATEGORY_BEGIN(Real)
        {
                TEST_BEGIN(Initialization)
                {
                        real x = real(1.0f);
                        EXPECT_FLOAT_EQ(__mfloat__ x, 1.0f);
                        free(x);
                }
                TEST_END()

                TEST_BEGIN(Trigonometry)
                {
                        // We have to be a little looser with our equality constraint
                        // because of floating-point precision issues.
                        const float trigAbsError = 0.0001f;

                        EXPECT_NEAR(__mfloat__ sin(real(0.0f)), 0.0f, trigAbsError);
                        EXPECT_NEAR(__mfloat__ sin(real(PI / 2)), 1.0f, trigAbsError);
                        EXPECT_NEAR(__mfloat__ sin(real(PI)), 0.0f, trigAbsError);
                        EXPECT_NEAR(__mfloat__ sin(real(3 * PI / 2)), -1.0f, trigAbsError);
                        EXPECT_NEAR(__mfloat__ sin(real(-PI / 2)), -1.0f, trigAbsError);

                        EXPECT_NEAR(__mfloat__ cos(real(0.0f)), 1.0f, trigAbsError);
                        EXPECT_NEAR(__mfloat__ cos(real(PI / 2)), 0.0f, trigAbsError);
                        EXPECT_NEAR(__mfloat__ cos(real(PI)), -1.0f, trigAbsError);
                        EXPECT_NEAR(__mfloat__ cos(real(3 * PI / 2)), 0.0f, trigAbsError);
                        EXPECT_NEAR(__mfloat__ cos(real(-PI)), -1.0f, trigAbsError);

                        EXPECT_NEAR(__mfloat__ tan(real(0.0f)), 0.0f, trigAbsError);
                        EXPECT_NEAR(__mfloat__ tan(real(PI / 4)), 1.0f, trigAbsError);
                        EXPECT_NEAR(__mfloat__ tan(real(3 * PI / 4)), -1.0f, trigAbsError);
                        EXPECT_NEAR(__mfloat__ tan(real(PI)), 0.0f, trigAbsError);
                        EXPECT_NEAR(__mfloat__ tan(real(-PI / 4)), -1.0f, trigAbsError);

                        // This isn't the most rigorous because we're really just sanity-
                        // checking that things work by default.
                }
                TEST_END()

                TEST_BEGIN(SquareRoot)
                {
                        EXPECT_FLOAT_EQ(__mfloat__ sqrt(real(16.0f)), 4.0f);
                        EXPECT_NEAR(__mfloat__ sqrt(real(10.0f)), 3.1616211f, 0.001f);
                }
                TEST_END()

                TEST_BEGIN(Power)
                {
                        EXPECT_FLOAT_EQ(__mfloat__ pow(real(2.0f), real(0)), 1.0f);
                        EXPECT_FLOAT_EQ(__mfloat__ pow(real(2.0f), real(4)), 16.0f);
                        EXPECT_FLOAT_EQ(__mfloat__ pow(real(2.0f), real(-2)), 0.25f);
                        EXPECT_NEAR(__mfloat__ pow(real(2.0f), real(4.1)), 17.148376f, 0.0001f);
                        EXPECT_NEAR(__mfloat__ pow(real(2.0f), real(-2.5)), 0.176777f, 0.0001f);
                }
                TEST_END()
        }
        CATEGORY_END()

        CATEGORY_BEGIN(Complex)
        {
                TEST_BEGIN(Initialization)
                {
                        complex z = complex(1.0f, 4.0f);
                        EXPECT_FLOAT_EQ(__mfloat__ creal(z), 1.0f);
                        EXPECT_FLOAT_EQ(__mfloat__ cimag(z), 4.0f);
                        free(z);
                }
                TEST_END()
        }
        CATEGORY_END()

        return 0;
}
