#include <stdio.h>
#include <cml.h>

real_t
f(real_t x, void *params)
{
        (void)(params); /* avoid unused parameter warning */
        return pow(x, 1.5);
}

int
main(void)
{
        function_t F;
        real_t result, abserr;

        F.function = &f;
        F.params = 0;

        printf("f(x) = x^(3/2)\n");

        deriv_central(&F, 2.0, 1e-8, &result, &abserr);
        printf("x = 2.0\n");
        printf("f'(x) = %.10f +/- %.10f\n", result, abserr);
        printf("exact = %.10f\n\n", 1.5 * sqrt(2.0));

        deriv_forward (&F, 0.0, 1e-8, &result, &abserr);
        printf("x = 0.0\n");
        printf("f'(x) = %.10f +/- %.10f\n", result, abserr);
        printf("exact = %.10f\n", 0.0);

        return 0;
}
