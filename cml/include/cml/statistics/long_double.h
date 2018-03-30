#ifndef CML_STATISTICS_H
#error "Never use <cml/statistics/long_double.h> directly; include <cml/statistics.h> instead."
#endif

#ifndef CML_STATISTICS_LONG_DOUBLE_H
#define CML_STATISTICS_LONG_DOUBLE_H

#include <stdlib.h>

__CML_BEGIN_DECLS

double cml_stats_long_double_mean(const long double data[], const size_t stride, const size_t n);
double cml_stats_long_double_variance(const long double data[], const size_t stride, const size_t n);
double cml_stats_long_double_sd(const long double data[], const size_t stride, const size_t n);
double cml_stats_long_double_variance_with_fixed_mean(const long double data[], const size_t stride, const size_t n, const double mean);
double cml_stats_long_double_sd_with_fixed_mean(const long double data[], const size_t stride, const size_t n, const double mean);
double cml_stats_long_double_tss(const long double data[], const size_t stride, const size_t n);
double cml_stats_long_double_tss_m(const long double data[], const size_t stride, const size_t n, const double mean);

double cml_stats_long_double_absdev(const long double data[], const size_t stride, const size_t n);
double cml_stats_long_double_skew(const long double data[], const size_t stride, const size_t n);
double cml_stats_long_double_kurtosis(const long double data[], const size_t stride, const size_t n);
double cml_stats_long_double_lag1_autocorrelation(const long double data[], const size_t stride, const size_t n);

double cml_stats_long_double_covariance(const long double data1[], const size_t stride1,const long double data2[], const size_t stride2, const size_t n);
double cml_stats_long_double_correlation(const long double data1[], const size_t stride1,const long double data2[], const size_t stride2, const size_t n);
double cml_stats_long_double_spearman(const long double data1[], const size_t stride1, const long double data2[], const size_t stride2, const size_t n, double work[]);

double cml_stats_long_double_variance_m(const long double data[], const size_t stride, const size_t n, const double mean);
double cml_stats_long_double_sd_m(const long double data[], const size_t stride, const size_t n, const double mean);
double cml_stats_long_double_absdev_m(const long double data[], const size_t stride, const size_t n, const double mean);
double cml_stats_long_double_skew_m_sd(const long double data[], const size_t stride, const size_t n, const double mean, const double sd);
double cml_stats_long_double_kurtosis_m_sd(const long double data[], const size_t stride, const size_t n, const double mean, const double sd);
double cml_stats_long_double_lag1_autocorrelation_m(const long double data[], const size_t stride, const size_t n, const double mean);

double cml_stats_long_double_covariance_m(const long double data1[], const size_t stride1,const long double data2[], const size_t stride2, const size_t n, const double mean1, const double mean2);


double cml_stats_long_double_pvariance(const long double data1[], const size_t stride1, const size_t n1, const long double data2[], const size_t stride2, const size_t n2);
double cml_stats_long_double_ttest(const long double data1[], const size_t stride1, const size_t n1, const long double data2[], const size_t stride2, const size_t n2);

long double cml_stats_long_double_max(const long double data[], const size_t stride, const size_t n);
long double cml_stats_long_double_min(const long double data[], const size_t stride, const size_t n);
void cml_stats_long_double_minmax(long double * min, long double * max, const long double data[], const size_t stride, const size_t n);

size_t cml_stats_long_double_max_index(const long double data[], const size_t stride, const size_t n);
size_t cml_stats_long_double_min_index(const long double data[], const size_t stride, const size_t n);
void cml_stats_long_double_minmax_index(size_t * min_index, size_t * max_index, const long double data[], const size_t stride, const size_t n);

double cml_stats_long_double_median_from_sorted_data(const long double sorted_data[], const size_t stride, const size_t n);
double cml_stats_long_double_quantile_from_sorted_data(const long double sorted_data[], const size_t stride, const size_t n, const double f);

__CML_END_DECLS

#endif /* CML_STATISTICS_LONG_DOUBLE_H */
