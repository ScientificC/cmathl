BASE
FUNCTION (cml_stats,max) (const BASE data[], const size_t stride,
                          const size_t n)
{
        /* finds the largest member of a dataset */

        BASE max = data[0 * stride];
        size_t i;

        for (i = 0; i < n; i++)
        {
                BASE xi = data[i * stride];

                if (xi > max)
                        max = xi;
#ifdef FP
                if (cml_isnan(xi))
                        return xi;
#endif
        }

        return max;
}

BASE
FUNCTION (cml_stats,min) (const BASE data[], const size_t stride,
                          const size_t n)
{
        /* finds the smallest member of a dataset */

        BASE min = data[0 * stride];
        size_t i;

        for (i = 0; i < n; i++)
        {
                BASE xi = data[i * stride];

                if (xi < min)
                        min = xi;
#ifdef FP
                if (cml_isnan(xi))
                        return xi;
#endif
        }

        return min;

}

void
FUNCTION (cml_stats,minmax) (BASE * min_out, BASE * max_out,
                             const BASE data[], const size_t stride,
                             const size_t n)
{
        /* finds the smallest and largest members of a dataset */

        BASE min = data[0 * stride];
        BASE max = data[0 * stride];
        size_t i;

        for (i = 0; i < n; i++)
        {
                BASE xi = data[i * stride];

                if (xi < min)
                        min = xi;

                if (xi > max)
                        max = xi;

#ifdef FP
                if (cml_isnan(xi))
                {
                        min = xi;
                        max = xi;
                        break;
                }
#endif

        }

        *min_out = min;
        *max_out = max;
}

size_t
FUNCTION (cml_stats,max_index) (const BASE data[], const size_t stride,
                                const size_t n)
{
        /* finds the index of the largest member of a dataset */
        /* if there is more than one largest value then we choose the first */

        BASE max = data[0 * stride];
        size_t i, max_index = 0;

        for (i = 0; i < n; i++)
        {
                BASE xi = data[i * stride];

                if (xi > max)
                {
                        max = xi;
                        max_index = i;
                }

#ifdef FP
                if (cml_isnan(xi))
                {
                        return i;
                }
#endif
        }

        return max_index;
}

size_t
FUNCTION (cml_stats,min_index) (const BASE data[], const size_t stride,
                                const size_t n)
{
        /* finds the index of the smallest member of a dataset */
        /* if there is more than one largest value then we choose the first  */

        BASE min = data[0 * stride];
        size_t i, min_index = 0;

        for (i = 0; i < n; i++)
        {
                BASE xi = data[i * stride];

                if (xi < min)
                {
                        min = xi;
                        min_index = i;
                }

#ifdef FP
                if (cml_isnan(xi))
                {
                        return i;
                }
#endif
        }

        return min_index;
}

void
FUNCTION (cml_stats,minmax_index) (size_t * min_index_out,
                                   size_t * max_index_out, const BASE data[],
                                   const size_t stride, const size_t n)
{
        /* finds the smallest and largest members of a dataset */

        BASE min = data[0 * stride];
        BASE max = data[0 * stride];
        size_t i, min_index = 0, max_index = 0;

        for (i = 0; i < n; i++)
        {
                BASE xi = data[i * stride];

                if (xi < min)
                {
                        min = xi;
                        min_index = i;
                }

                if (xi > max)
                {
                        max = xi;
                        max_index = i;
                }

#ifdef FP
                if (cml_isnan(xi))
                {
                        min_index = i;
                        max_index = i;
                        break;
                }
#endif
        }

        *min_index_out = min_index;
        *max_index_out = max_index;
}
