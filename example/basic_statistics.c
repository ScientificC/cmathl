#include <stdio.h>
#include <cml/statistics.h>

int
main(int argc, char** argv)
{
        double data[5] = {17.2, 18.1, 16.5, 18.3, 12.6};
        double mean, variance, largest, smallest;

        mean = cml_stats_mean(data, 1, 5);
        variance = cml_stats_variance(data, 1, 5);

        printf("The dataset is %g, %g, %g, %g, %g\n",
               data[0], data[1], data[2], data[3], data[4]);

        printf("The sample mean is %g\n", mean);
        printf("The estimated variance is %g\n", variance);

        return 0;
}
