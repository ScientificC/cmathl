double
FUNCTION(cml_stats,absdev) (const BASE data[], const size_t stride,
                            const size_t n)
{
        const double mean = FUNCTION(cml_stats,mean)(data, stride, n);
        return FUNCTION(cml_stats,absdev_m)(data, stride, n, mean);
}

double
FUNCTION(cml_stats,absdev_m) (const BASE data[], const size_t stride,
                              const size_t n, const double mean)
{
        /* takes a dataset and finds the absolute deviation */

        double sum = 0, absdev;
        size_t i;

        /* find the sum of the absolute deviations */
        for (i = 0; i < n; i++)
        {
                const double delta = cml_abs(data[i * stride] - mean);
                sum += delta;
        }

        absdev = sum / n;

        return absdev;
}
