double
FUNCTION(cml_stats, kurtosis)(const BASE data[], const size_t stride, const size_t n)
{
        const double mean = FUNCTION(cml_stats, mean)(data, stride, n);
        const double est_sd = FUNCTION(cml_stats, sd_m)(data, stride, n, mean);
        return FUNCTION(cml_stats, kurtosis_m_sd)(data, stride, n, mean, est_sd);
}

double
FUNCTION(cml_stats, kurtosis_m_sd)(const BASE data[], const size_t stride,
                                   const size_t n, const double mean,
                                   const double sd)
{
        /* takes a dataset and finds the kurtosis */

        long double avg = 0.0L, kurtosis;
        size_t i;

        /* find the fourth moment the deviations, normalized by the sd */

        /* we use a recurrence relation to stably update a running value so
           there aren't any large sums that can overflow */

        for (i = 0; i < n; i++)
        {
                const long double x = (data[i * stride] - mean) / sd;
                avg += (x * x * x * x - avg)/(i + 1);
        }

        kurtosis = avg - 3.0; /* makes kurtosis zero for a Gaussian */

        return (double) kurtosis;
}
