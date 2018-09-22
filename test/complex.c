#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <cml/math.h>
#include <cml/complex.h>
#include "include/test.h"

int cml_count_tests = 0;
int cml_count_failedtests = 0;
int cml_count_failures = 0;

struct cml_complex_tests
{
        char *name;
        cml_complex_t (*f) (cml_complex_t);
        double arg_re;
        double arg_im;
        double res_re;
        double res_im;
};

struct cml_complex_tests list_tst[] =
{
#include "data/complex.dat"
        { "", NULL, 0.0, 0.0, 0.0, 0.0 }
};


int
run_complex_tests()
{
        CATEGORY_BEGIN(Complex)
        {
                TEST_BEGIN(Initialization)
                {
                        cml_complex_t z = cml_complex(1.0, 4.0);
                        EXPECT_FLOAT_EQ(z.re, 1.0);
                        EXPECT_FLOAT_EQ(z.im, 4.0);
                }
                TEST_END()

                TEST_BEGIN(Functions)
                {
                        size_t i;

                        for (i = 0; list_tst[i].f != NULL; i++ )
                        {
                                struct cml_complex_tests t = list_tst[i];
                                cml_complex_t arg = cml_complex(t.arg_re, t.arg_im);
                                cml_complex_t res = (t.f)(arg);

                                #ifdef CML_NO_MATH
                                EXPECT_NEAR(res.re, t.res_re, 1e-4);
                                EXPECT_NEAR(res.im, t.res_im, 1e-4);
                                #else
                                EXPECT_FLOAT_EQ(res.re, t.res_re);
                                EXPECT_FLOAT_EQ(res.im, t.res_im);
                                #endif
                        }
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

        run_complex_tests();

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
