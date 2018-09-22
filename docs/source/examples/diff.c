#include <stdio.h>
#include <cml/math.h>
#include <cml/diff.h>

double
f(double x, void *params)
{
        (void) params; /* avoid unused parameter warning */
        return cml_pow(x, 1.5);
}

int
main(void)
{
        cml_function_t F;
        double result, abserr;

        F.function = &f;
        F.params = 0;

        printf("f(x) = x^(3/2)\n");

        cml_deriv_central(&F, 2.0, 1e-8, &result, &abserr);
        printf("x = 2.0\n");
        printf("f'(x) = %.10f +/- %.10f\n", result, abserr);
        printf("exact = %.10f\n\n", 1.5 * sqrt(2.0));

        cml_deriv_forward (&F, 0.0, 1e-8, &result, &abserr);
        printf("x = 0.0\n");
        printf("f'(x) = %.10f +/- %.10f\n", result, abserr);
        printf("exact = %.10f\n", 0.0);

        return 0;
}
