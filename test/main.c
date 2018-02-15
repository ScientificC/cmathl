#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <cml.h>
#include "include/test.h"

int cml_count_tests = 0;
int cml_count_failedtests = 0;
int cml_count_failures = 0;

int run_complex_tests();
int run_diff_tests();
int run_easings_tests();
int run_real_tests();
int run_struct_tests();

int
run_tests()
{
        run_complex_tests();
        #ifndef CML_NO_MATH
        run_diff_tests();
        #endif

        run_real_tests();

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
