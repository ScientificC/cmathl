double
FUNCTION(cml_stats,pvariance) (const BASE data1[],
                               const size_t stride1, const size_t n1,
                               const BASE data2[],
                               const size_t stride2, const size_t n2)
{
        /* Find the pooled variance of two datasets */

        const double var1 = FUNCTION(cml_stats,variance) (data1, stride1, n1);
        const double var2 = FUNCTION(cml_stats,variance) (data2, stride2, n2);

        /* calculate the pooled variance */

        const double pooled_variance =
                (((n1 - 1) * var1) + ((n2 - 1) * var2)) / (n1 + n2 - 2);

        return pooled_variance;
}
