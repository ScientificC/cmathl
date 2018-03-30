static double
FUNCTION(compute, variance)(const BASE data[], const size_t stride,
                            const size_t n, const double mean);


static double
FUNCTION(compute, tss)(const BASE data[], const size_t stride,
                       const size_t n, const double mean);


static double
FUNCTION(compute, variance)(const BASE data[], const size_t stride,
                            const size_t n, const double mean)
{
        /* takes a dataset and finds the variance */

        long double variance = 0.0L;

        size_t i;

        /* find the sum of the squares */
        for (i = 0; i < n; i++)
        {
                const long double delta = (data[i * stride] - mean);
                variance += (delta * delta - variance) / (i + 1);
        }

        return (double) variance;
}


static double
FUNCTION(compute, tss)(const BASE data[], const size_t stride,
                       const size_t n, const double mean)
{
        /* takes a dataset and finds the sum of squares about the mean */

        long double tss = 0;

        size_t i;

        /* find the sum of the squares */
        for (i = 0; i < n; i++)
        {
                const long double delta = (data[i * stride] - mean);
                tss += delta * delta;
        }

        return (double) tss;
}


double
FUNCTION(cml_stats, variance_with_fixed_mean)(const BASE data[],
                                              const size_t stride,
                                              const size_t n,
                                              const double mean)
{
        const double variance = FUNCTION(compute, variance)(data, stride, n, mean);
        return variance;
}


double
FUNCTION(cml_stats, sd_with_fixed_mean)(const BASE data[], const size_t stride,
                                        const size_t n, const double mean)
{
        const double variance = FUNCTION(compute, variance)(data, stride, n, mean);
        const double sd = cml_sqrt(variance);

        return sd;
}



double
FUNCTION(cml_stats, variance_m)(const BASE data[], const size_t stride,
                                const size_t n, const double mean)
{
        const double variance = FUNCTION(compute, variance)(data, stride, n, mean);

        return variance * ((double)n / (double)(n - 1));
}


double
FUNCTION(cml_stats, sd_m)(const BASE data[], const size_t stride,
                          const size_t n, const double mean)
{
        const double variance = FUNCTION(compute, variance)(data, stride, n, mean);
        const double sd = cml_sqrt(variance * ((double)n / (double)(n - 1)));

        return sd;
}


double
FUNCTION(cml_stats, variance)(const BASE data[], const size_t stride, const size_t n)
{
        const double mean = FUNCTION(cml_stats, mean)(data, stride, n);
        return FUNCTION(cml_stats, variance_m)(data, stride, n, mean);
}


double
FUNCTION(cml_stats, sd)(const BASE data[], const size_t stride, const size_t n)
{
        const double mean = FUNCTION(cml_stats, mean)(data, stride, n);
        return FUNCTION(cml_stats, sd_m)(data, stride, n, mean);
}


double
FUNCTION(cml_stats, tss_m)(const BASE data[], const size_t stride,
                           const size_t n, const double mean)
{
        const double tss = FUNCTION(compute, tss)(data, stride, n, mean);

        return tss;
}


double
FUNCTION(cml_stats, tss)(const BASE data[], const size_t stride, const size_t n)
{
        const double mean = FUNCTION(cml_stats, mean)(data, stride, n);
        return FUNCTION(cml_stats, tss_m)(data, stride, n, mean);
}
