#ifndef CML_STATISTICS_H
#error "Never use <cml/statistics/float.h> directly; include <cml/statistics.h> instead."
#endif

#ifndef CML_STATISTICS_FLOAT_H
#define CML_STATISTICS_FLOAT_H

#include <stdlib.h>

__CML_BEGIN_DECLS

double cml_stats_float_mean(const float data[], const size_t stride, const size_t n);
double cml_stats_float_variance(const float data[], const size_t stride, const size_t n);
double cml_stats_float_sd(const float data[], const size_t stride, const size_t n);
double cml_stats_float_variance_with_fixed_mean(const float data[], const size_t stride, const size_t n, const double mean);
double cml_stats_float_sd_with_fixed_mean(const float data[], const size_t stride, const size_t n, const double mean);
double cml_stats_float_tss(const float data[], const size_t stride, const size_t n);
double cml_stats_float_tss_m(const float data[], const size_t stride, const size_t n, const double mean);

double cml_stats_float_kurtosis(const float data[], const size_t stride, const size_t n);

double cml_stats_float_covariance(const float data1[], const size_t stride1, const float data2[], const size_t stride2, const size_t n);

double cml_stats_float_variance_m(const float data[], const size_t stride, const size_t n, const double mean);
double cml_stats_float_sd_m(const float data[], const size_t stride, const size_t n, const double mean);
double cml_stats_float_kurtosis_m_sd(const float data[], const size_t stride, const size_t n, const double mean, const double sd);

double cml_stats_float_median_from_sorted_data(const float sorted_data[], const size_t stride, const size_t n);
double cml_stats_float_quantile_from_sorted_data(const float sorted_data[], const size_t stride, const size_t n, const double f);

__CML_END_DECLS

#endif /* CML_STATISTICS_FLOAT_H */
