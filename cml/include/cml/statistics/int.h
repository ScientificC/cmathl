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

double cml_stats_int_absdev(const int data[], const size_t stride, const size_t n);
double cml_stats_int_skew(const int data[], const size_t stride, const size_t n);
double cml_stats_int_kurtosis(const int data[], const size_t stride, const size_t n);
double cml_stats_int_lag1_autocorrelation(const int data[], const size_t stride, const size_t n);

double cml_stats_int_covariance(const int data1[], const size_t stride1,const int data2[], const size_t stride2, const size_t n);
double cml_stats_int_correlation(const int data1[], const size_t stride1,const int data2[], const size_t stride2, const size_t n);
double cml_stats_int_spearman(const int data1[], const size_t stride1, const int data2[], const size_t stride2, const size_t n, double work[]);

double cml_stats_int_variance_m(const int data[], const size_t stride, const size_t n, const double mean);
double cml_stats_int_sd_m(const int data[], const size_t stride, const size_t n, const double mean);
double cml_stats_int_absdev_m(const int data[], const size_t stride, const size_t n, const double mean);
double cml_stats_int_skew_m_sd(const int data[], const size_t stride, const size_t n, const double mean, const double sd);
double cml_stats_int_kurtosis_m_sd(const int data[], const size_t stride, const size_t n, const double mean, const double sd);
double cml_stats_int_lag1_autocorrelation_m(const int data[], const size_t stride, const size_t n, const double mean);

double cml_stats_int_covariance_m(const int data1[], const size_t stride1,const int data2[], const size_t stride2, const size_t n, const double mean1, const double mean2);


double cml_stats_int_pvariance(const int data1[], const size_t stride1, const size_t n1, const int data2[], const size_t stride2, const size_t n2);
double cml_stats_int_ttest(const int data1[], const size_t stride1, const size_t n1, const int data2[], const size_t stride2, const size_t n2);

int cml_stats_int_max(const int data[], const size_t stride, const size_t n);
int cml_stats_int_min(const int data[], const size_t stride, const size_t n);
void cml_stats_int_minmax(int * min, int * max, const int data[], const size_t stride, const size_t n);

size_t cml_stats_int_max_index(const int data[], const size_t stride, const size_t n);
size_t cml_stats_int_min_index(const int data[], const size_t stride, const size_t n);
void cml_stats_int_minmax_index(size_t * min_index, size_t * max_index, const int data[], const size_t stride, const size_t n);

double cml_stats_int_median_from_sorted_data(const int sorted_data[], const size_t stride, const size_t n);
double cml_stats_int_quantile_from_sorted_data(const int sorted_data[], const size_t stride, const size_t n, const double f);

__CML_END_DECLS

#endif /* CML_STATISTICS_INT_H */
