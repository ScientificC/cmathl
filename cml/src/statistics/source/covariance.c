static double
FUNCTION(compute, covariance)(const BASE data1[], const size_t stride1,
                              const BASE data2[], const size_t stride2,
                              const size_t n,
                              const double mean1, const double mean2);


static double
FUNCTION(compute, covariance)(const BASE data1[], const size_t stride1,
                              const BASE data2[], const size_t stride2,
                              const size_t n,
                              const double mean1, const double mean2)
{
        /* takes a dataset and finds the covariance */

        long double covariance = 0.0L;

        size_t i;

        /* find the sum of the squares */
        for (i = 0; i < n; i++)
        {
                const long double delta1 = (data1[i * stride1] - mean1);
                const long double delta2 = (data2[i * stride2] - mean2);
                covariance += (delta1 * delta2 - covariance) / (i + 1);
        }

        return (double) covariance;
}


double
FUNCTION(cml_stats, covariance_m)(const BASE data1[], const size_t stride1,
                                  const BASE data2[], const size_t stride2,
                                  const size_t n,
                                  const double mean1, const double mean2)
{
        const double covariance = FUNCTION(compute, covariance)(data1, stride1,
                                                                data2, stride2,
                                                                n,
                                                                mean1, mean2);

        return covariance * ((double)n / (double)(n - 1));
}


double
FUNCTION(cml_stats, covariance)(const BASE data1[], const size_t stride1,
                                const BASE data2[], const size_t stride2,
                                const size_t n)
{
        const double mean1 = FUNCTION(cml_stats, mean)(data1, stride1, n);
        const double mean2 = FUNCTION(cml_stats, mean)(data2, stride2, n);

        return FUNCTION(cml_stats, covariance_m)(data1, stride1,
                                                 data2, stride2,
                                                 n,
                                                 mean1, mean2);
}
