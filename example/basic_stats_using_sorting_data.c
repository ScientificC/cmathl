#include <stdio.h>
#include <cml/statistics.h>

int
main(int argc, char** argv)
{
        double data[5] = { 12.6, 16.5, 17.2, 18.1, 18.3};
        double median, upperq, lowerq;

        printf ("Sorted dataset: %g, %g, %g, %g, %g\n",
                data[0], data[1], data[2], data[3], data[4]);

        median = cml_stats_median_from_sorted_data(data, 1, 5);

        upperq = cml_stats_quantile_from_sorted_data(data, 1, 5, 0.75);
        lowerq = cml_stats_quantile_from_sorted_data(data, 1, 5, 0.25);

        printf ("The median is %g\n", median);
        printf ("The upper quartile is %g\n", upperq);
        printf ("The lower quartile is %g\n", lowerq);

        return 0;
}
