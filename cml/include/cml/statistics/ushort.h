#ifndef CML_STATISTICS_H
#error "Never use <cml/statistics/ushort.h> directly; include <cml/statistics.h> instead."
#endif

#ifndef CML_STATISTICS_USHORT_H
#define CML_STATISTICS_USHORT_H

#include <stdlib.h>

__CML_BEGIN_DECLS

double cml_stats_ushort_mean(const unsigned short data[], const size_t stride, const size_t n);
double cml_stats_ushort_variance(const unsigned short data[], const size_t stride, const size_t n);
double cml_stats_ushort_sd(const unsigned short data[], const size_t stride, const size_t n);
double cml_stats_ushort_variance_with_fixed_mean(const unsigned short data[], const size_t stride, const size_t n, const double mean);
double cml_stats_ushort_sd_with_fixed_mean(const unsigned short data[], const size_t stride, const size_t n, const double mean);
double cml_stats_ushort_tss(const unsigned short data[], const size_t stride, const size_t n);
double cml_stats_ushort_tss_m(const unsigned short data[], const size_t stride, const size_t n, const double mean);

double cml_stats_ushort_absdev(const unsigned short data[], const size_t stride, const size_t n);
double cml_stats_ushort_skew(const unsigned short data[], const size_t stride, const size_t n);
double cml_stats_ushort_kurtosis(const unsigned short data[], const size_t stride, const size_t n);
double cml_stats_ushort_lag1_autocorrelation(const unsigned short data[], const size_t stride, const size_t n);

double cml_stats_ushort_covariance(const unsigned short data1[], const size_t stride1,const unsigned short data2[], const size_t stride2, const size_t n);
double cml_stats_ushort_correlation(const unsigned short data1[], const size_t stride1,const unsigned short data2[], const size_t stride2, const size_t n);
double cml_stats_ushort_spearman(const unsigned short data1[], const size_t stride1, const unsigned short data2[], const size_t stride2, const size_t n, double work[]);

double cml_stats_ushort_variance_m(const unsigned short data[], const size_t stride, const size_t n, const double mean);
double cml_stats_ushort_sd_m(const unsigned short data[], const size_t stride, const size_t n, const double mean);
double cml_stats_ushort_absdev_m(const unsigned short data[], const size_t stride, const size_t n, const double mean);
double cml_stats_ushort_skew_m_sd(const unsigned short data[], const size_t stride, const size_t n, const double mean, const double sd);
double cml_stats_ushort_kurtosis_m_sd(const unsigned short data[], const size_t stride, const size_t n, const double mean, const double sd);
double cml_stats_ushort_lag1_autocorrelation_m(const unsigned short data[], const size_t stride, const size_t n, const double mean);

double cml_stats_ushort_covariance_m(const unsigned short data1[], const size_t stride1,const unsigned short data2[], const size_t stride2, const size_t n, const double mean1, const double mean2);


double cml_stats_ushort_pvariance(const unsigned short data1[], const size_t stride1, const size_t n1, const unsigned short data2[], const size_t stride2, const size_t n2);
double cml_stats_ushort_ttest(const unsigned short data1[], const size_t stride1, const size_t n1, const unsigned short data2[], const size_t stride2, const size_t n2);

unsigned short cml_stats_ushort_max(const unsigned short data[], const size_t stride, const size_t n);
unsigned short cml_stats_ushort_min(const unsigned short data[], const size_t stride, const size_t n);
void cml_stats_ushort_minmax(unsigned short * min, unsigned short * max, const unsigned short data[], const size_t stride, const size_t n);

size_t cml_stats_ushort_max_index(const unsigned short data[], const size_t stride, const size_t n);
size_t cml_stats_ushort_min_index(const unsigned short data[], const size_t stride, const size_t n);
void cml_stats_ushort_minmax_index(size_t * min_index, size_t * max_index, const unsigned short data[], const size_t stride, const size_t n);

double cml_stats_ushort_median_from_sorted_data(const unsigned short sorted_data[], const size_t stride, const size_t n);
double cml_stats_ushort_quantile_from_sorted_data(const unsigned short sorted_data[], const size_t stride, const size_t n, const double f);

__CML_END_DECLS

#endif /* CML_STATISTICS_USHORT_H */
