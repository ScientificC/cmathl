#ifndef CML_STATISTICS_H
#error "Never use <cml/statistics/double.h> directly; include <cml/statistics.h> instead."
#endif

#ifndef CML_STATISTICS_DOUBLE_H
#define CML_STATISTICS_DOUBLE_H

#include <stdlib.h>

__CML_BEGIN_DECLS

double cml_stats_mean(const double data[], const size_t stride, const size_t n);
double cml_stats_variance(const double data[], const size_t stride, const size_t n);
double cml_stats_sd(const double data[], const size_t stride, const size_t n);
double cml_stats_variance_with_fixed_mean(const double data[], const size_t stride, const size_t n, const double mean);
double cml_stats_sd_with_fixed_mean(const double data[], const size_t stride, const size_t n, const double mean);
double cml_stats_tss(const double data[], const size_t stride, const size_t n);
double cml_stats_tss_m(const double data[], const size_t stride, const size_t n, const double mean);

double cml_stats_kurtosis(const double data[], const size_t stride, const size_t n);

double cml_stats_covariance(const double data1[], const size_t stride1, const double data2[], const size_t stride2, const size_t n);

double cml_stats_variance_m(const double data[], const size_t stride, const size_t n, const double mean);
double cml_stats_sd_m(const double data[], const size_t stride, const size_t n, const double mean);
double cml_stats_kurtosis_m_sd(const double data[], const size_t stride, const size_t n, const double mean, const double sd);

double cml_stats_median_from_sorted_data(const double sorted_data[], const size_t stride, const size_t n);
double cml_stats_quantile_from_sorted_data(const double sorted_data[], const size_t stride, const size_t n, const double f);

__CML_END_DECLS

#endif /* CML_STATISTICS_DOUBLE_H */
