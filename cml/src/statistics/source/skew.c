double
FUNCTION(cml_stats,skew) (const BASE data[], const size_t stride,
                          const size_t n)
{
        const double mean = FUNCTION(cml_stats,mean)(data, stride, n);
        const double sd = FUNCTION(cml_stats,sd_m)(data, stride, n, mean);

        return FUNCTION(cml_stats,skew_m_sd)(data, stride, n, mean, sd);
}

double
FUNCTION(cml_stats,skew_m_sd) (const BASE data[],
                               const size_t stride, const size_t n,
                               const double mean, const double sd)
{
        /* takes a dataset and finds the skewness */

        long double skew = 0;
        size_t i;

        /* find the sum of the cubed deviations, normalized by the sd. */

        /* we use a recurrence relation to stably update a running value so
         * there aren't any large sums that can overflow
         */

        for (i = 0; i < n; i++)
        {
                const long double x = (data[i * stride] - mean) / sd;
                skew += (x * x * x - skew) / (i + 1);
        }

        return skew;
}
