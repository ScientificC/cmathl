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
        run_tests();

        if (cml_count_failedtests > 0) {
                printf(RED);
        } else {
                printf(GREEN);
        }

        printf("\n%d/%d tests passed overall, %d failures\n" RESET, cml_count_tests - cml_count_failedtests, cml_count_tests, cml_count_failures);

        printf("\n");

        return (cml_count_failedtests > 0);

        return 0;
}

int run_tests()
{
        CATEGORY_BEGIN(Real)
        {
                TEST_BEGIN(Initialization)
                {
                        real x = real(1.0f);
                        EXPECT_FLOAT_EQ(real_value(x), 1.0f);
                }
                TEST_END()
        }
        CATEGORY_END()

        CATEGORY_BEGIN(Complex)
        {
                TEST_BEGIN(Initialization)
                {
                        complex z = complex(1.0f, 4.0f);
                        EXPECT_FLOAT_EQ(real_value(complex_get_real(z)), 1.0f);
                        EXPECT_FLOAT_EQ(real_value(complex_get_imaginary(z)), 4.0f);
                }
                TEST_END()
        }
        CATEGORY_END()

        return 0;
}
