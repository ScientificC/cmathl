double
FUNCTION(cml_stats, median_from_sorted_data)(const BASE sorted_data[],
                                             const size_t stride,
                                             const size_t n)
{
        if (n == 0)
        {
                return 0.0;
        }

        double median;
        const size_t lhs = (n - 1) / 2;
        const size_t rhs = n / 2;

        if (lhs == rhs)
        {
                median = sorted_data[lhs * stride];
        }
        else
        {
                median = (sorted_data[lhs * stride] + sorted_data[rhs * stride])/2.0;
        }

        return median;
}
