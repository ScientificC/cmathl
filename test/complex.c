#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <cml.h>
#include "include/test.h"


int
run_complex_tests()
{
        CATEGORY_BEGIN(Complex)
        {
                TEST_BEGIN(Initialization)
                {
                        complex_t z = complex(1.0, 4.0);
                        EXPECT_FLOAT_EQ(z.re, 1.0);
                        EXPECT_FLOAT_EQ(z.im, 4.0);
                }
                TEST_END()
        }
        CATEGORY_END()

        return 0;
}
