#include <stdio.h>
#include <cml.h>

int
main(void)
{
        real_t c  = CML_CONST_MKSA_SPEED_OF_LIGHT;
        real_t au = CML_CONST_MKSA_ASTRONOMICAL_UNIT;
        real_t minutes = CML_CONST_MKSA_MINUTE;

        /* distance stored in meters */
        real_t r_earth = 1.00 * au;
        real_t r_mars  = 1.52 * au;

        real_t t_min, t_max;

        t_min = (r_mars - r_earth) / c;
        t_max = (r_mars + r_earth) / c;

        printf("light travel time from Earth to Mars:\n");
        printf("minimum = %.1f minutes\n", t_min / minutes);
        printf("maximum = %.1f minutes\n", t_max / minutes);

        return 0;
}
