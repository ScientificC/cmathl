#ifndef CML_STATISTICS_H
#error "Never use <cml/statistics/int.h> directly; include <cml/statistics.h> instead."
#endif

#ifndef CML_STATISTICS_INT_H
#define CML_STATISTICS_INT_H

#include <stdlib.h>

__CML_BEGIN_DECLS

double cml_stats_int_mean(const int data[], const size_t stride, const size_t n);
double cml_stats_int_variance(const int data[], const size_t stride, const size_t n);
double cml_stats_int_sd(const int data[], const size_t stride, const size_t n);
double cml_stats_int_variance_with_fixed_mean(const int data[], const size_t stride, const size_t n, const double mean);
double cml_stats_int_sd_with_fixed_mean(const int data[], const size_t stride, const size_t n, const double mean);
double cml_stats_int_tss(const int data[], const size_t stride, const size_t n);
double cml_stats_int_tss_m(const int data[], const size_t stride, const size_t n, const double mean);

double cml_stats_int_kurtosis(const int data[], const size_t stride, const size_t n);

double cml_stats_int_covariance(const int data1[], const size_t stride1, const int data2[], const size_t stride2, const size_t n);

double cml_stats_int_variance_m(const int data[], const size_t stride, const size_t n, const double mean);
double cml_stats_int_sd_m(const int data[], const size_t stride, const size_t n, const double mean);
double cml_stats_int_kurtosis_m_sd(const int data[], const size_t stride, const size_t n, const double mean, const double sd);

double cml_stats_int_median_from_sorted_data(const int sorted_data[], const size_t stride, const size_t n);
double cml_stats_int_quantile_from_sorted_data(const int sorted_data[], const size_t stride, const size_t n, const double f);

__CML_END_DECLS

#endif /* CML_STATISTICS_INT_H */
