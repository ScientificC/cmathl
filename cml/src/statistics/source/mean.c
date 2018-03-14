double
FUNCTION(cml_stats, mean)(const BASE data[], const size_t stride, const size_t size)
{
        /* Compute the arithmetic mean of a dataset using the recurrence relation
           mean(n) = mean(n-1) + (data[n] - mean(n-1))/(n+1)   */

        long double mean = 0.0L;
        size_t i;

        for (i = 0; i < size; i++)
        {
                mean += (data[i * stride] - mean) / (i + 1);
        }

        return (double) mean;
}
