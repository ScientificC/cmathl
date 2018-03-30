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

double cml_stats_absdev(const double data[], const size_t stride, const size_t n);
double cml_stats_skew(const double data[], const size_t stride, const size_t n);
double cml_stats_kurtosis(const double data[], const size_t stride, const size_t n);
double cml_stats_lag1_autocorrelation(const double data[], const size_t stride, const size_t n);

double cml_stats_covariance(const double data1[], const size_t stride1,const double data2[], const size_t stride2, const size_t n);
double cml_stats_correlation(const double data1[], const size_t stride1,const double data2[], const size_t stride2, const size_t n);
double cml_stats_spearman(const double data1[], const size_t stride1, const double data2[], const size_t stride2, const size_t n, double work[]);

double cml_stats_variance_m(const double data[], const size_t stride, const size_t n, const double mean);
double cml_stats_sd_m(const double data[], const size_t stride, const size_t n, const double mean);
double cml_stats_absdev_m(const double data[], const size_t stride, const size_t n, const double mean);
double cml_stats_skew_m_sd(const double data[], const size_t stride, const size_t n, const double mean, const double sd);
double cml_stats_kurtosis_m_sd(const double data[], const size_t stride, const size_t n, const double mean, const double sd);
double cml_stats_lag1_autocorrelation_m(const double data[], const size_t stride, const size_t n, const double mean);

double cml_stats_covariance_m(const double data1[], const size_t stride1,const double data2[], const size_t stride2, const size_t n, const double mean1, const double mean2);


double cml_stats_pvariance(const double data1[], const size_t stride1, const size_t n1, const double data2[], const size_t stride2, const size_t n2);
double cml_stats_ttest(const double data1[], const size_t stride1, const size_t n1, const double data2[], const size_t stride2, const size_t n2);

double cml_stats_max(const double data[], const size_t stride, const size_t n);
double cml_stats_min(const double data[], const size_t stride, const size_t n);
void cml_stats_minmax(double * min, double * max, const double data[], const size_t stride, const size_t n);

size_t cml_stats_max_index(const double data[], const size_t stride, const size_t n);
size_t cml_stats_min_index(const double data[], const size_t stride, const size_t n);
void cml_stats_minmax_index(size_t * min_index, size_t * max_index, const double data[], const size_t stride, const size_t n);

double cml_stats_median_from_sorted_data(const double sorted_data[], const size_t stride, const size_t n);
double cml_stats_quantile_from_sorted_data(const double sorted_data[], const size_t stride, const size_t n, const double f);

__CML_END_DECLS

#endif /* CML_STATISTICS_DOUBLE_H */
