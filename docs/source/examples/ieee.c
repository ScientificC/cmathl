#include <stdio.h>
#include <cml.h>

int
main(void)
{
        float f = 1.0/3.0;
        double d = 1.0/3.0;

        double fd = f; /* promote from float to double */

        printf(" f = ");
        cml_ieee754_printf_float(&f);
        printf("\n");

        printf("fd = ");
        cml_ieee754_printf_double(&fd);
        printf("\n");

        printf(" d = ");
        cml_ieee754_printf_double(&d);
        printf("\n");

        return 0;
}
