#ifndef CML_STATISTICS_H
#error "Never use <cml/statistics/unsigned_long.h> directly; include <cml/statistics.h> instead."
#endif

#ifndef CML_STATISTICS_ULONG_H
#define CML_STATISTICS_ULONG_H

#include <stdlib.h>

__CML_BEGIN_DECLS

double cml_stats_ulong_mean(const unsigned long data[], const size_t stride, const size_t n);
double cml_stats_ulong_variance(const unsigned long data[], const size_t stride, const size_t n);
double cml_stats_ulong_sd(const unsigned long data[], const size_t stride, const size_t n);
double cml_stats_ulong_variance_with_fixed_mean(const unsigned long data[], const size_t stride, const size_t n, const double mean);
double cml_stats_ulong_sd_with_fixed_mean(const unsigned long data[], const size_t stride, const size_t n, const double mean);
double cml_stats_ulong_tss(const unsigned long data[], const size_t stride, const size_t n);
double cml_stats_ulong_tss_m(const unsigned long data[], const size_t stride, const size_t n, const double mean);

double cml_stats_ulong_kurtosis(const unsigned long data[], const size_t stride, const size_t n);

double cml_stats_ulong_covariance(const unsigned long data1[], const size_t stride1,const unsigned long data2[], const size_t stride2, const size_t n);

double cml_stats_ulong_variance_m(const unsigned long data[], const size_t stride, const size_t n, const double mean);
double cml_stats_ulong_sd_m(const unsigned long data[], const size_t stride, const size_t n, const double mean);
double cml_stats_ulong_kurtosis_m_sd(const unsigned long data[], const size_t stride, const size_t n, const double mean, const double sd);

double cml_stats_ulong_median_from_sorted_data(const unsigned long sorted_data[], const size_t stride, const size_t n);
double cml_stats_ulong_quantile_from_sorted_data(const unsigned long sorted_data[], const size_t stride, const size_t n, const double f);

__CML_END_DECLS

#endif /* CML_STATISTICS_ULONG_H */
