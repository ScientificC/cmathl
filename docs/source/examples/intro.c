#include <stdlib.h>
#include <stdio.h>
#include <cml.h>

int
main(int argc, char const *argv[])
{
        complex_t z, w;

        z = complex(1.0, 2.0);
        w = csin(z);

        printf("%g\n", sin(2.0));
        printf("%g\n", atan2(2.0, 3.0));
        printf("%g\n", creal(w));
        printf("%g\n", cimag(w));

        return 0;
}
