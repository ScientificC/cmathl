#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <cml.h>
#include "include/test.h"

struct complex_tests
{
        complex_t (*f) (complex_t);
        real_t arg_re;
        real_t arg_im;
        real_t res_re;
        real_t res_im;
};

struct complex_tests list_tst[] =
{
#include "complex.dat"
        { NULL, 0, 0, 0, 0}
};


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

                TEST_BEGIN(Functions)
                {
                        /* size_t i;
                           real_t tol  = 1e6 * CML_DBL_EPSILON;

                           for (i = 0; list_tst[i].f != NULL; i++ )
                           {
                                struct complex_tests t = list_tst[i];
                                complex_t arg = complex(t.arg_re, t.arg_im);
                                complex_t res = (t.f)(arg);

                                EXPECT_FLOAT_EQ(res.re, t.res_re);
                                EXPECT_FLOAT_EQ(res.im, t.res_im);
                           }*/
                }
                TEST_END()
        }
        CATEGORY_END()

        return 0;
}
