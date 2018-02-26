#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "include/test.h"

int cml_count_tests = 0;
int cml_count_failedtests = 0;
int cml_count_failures = 0;

int run_cml_complex_tests();
int run_cml_deriv_tests();
int run_cml_diff_tests();
int run_easings_tests();
int run_doubleests();
int run_struct_tests();

int
run_tests()
{
        run_cml_complex_tests();
        run_cml_deriv_tests();
        run_cml_diff_tests();
        run_doubleests();

        #ifndef CML_NO_EASING_FUNCTIONS
        run_easings_tests();
        #endif

        #ifndef CML_NO_STRUCTURES
        run_struct_tests();
        #endif

        return 0;
}

int
main()
{
        clock_t cl = clock();

        run_tests();

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
