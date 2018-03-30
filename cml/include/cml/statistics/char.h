#ifndef CML_STATISTICS_H
#error "Never use <cml/statistics/char.h> directly; include <cml/statistics.h> instead."
#endif

#ifndef CML_STATISTICS_CHAR_H
#define CML_STATISTICS_CHAR_H

#include <stdlib.h>

__CML_BEGIN_DECLS

double cml_stats_char_mean(const char data[], const size_t stride, const size_t n);
double cml_stats_char_variance(const char data[], const size_t stride, const size_t n);
double cml_stats_char_sd(const char data[], const size_t stride, const size_t n);
double cml_stats_char_variance_with_fixed_mean(const char data[], const size_t stride, const size_t n, const double mean);
double cml_stats_char_sd_with_fixed_mean(const char data[], const size_t stride, const size_t n, const double mean);
double cml_stats_char_tss(const char data[], const size_t stride, const size_t n);
double cml_stats_char_tss_m(const char data[], const size_t stride, const size_t n, const double mean);

double cml_stats_char_absdev(const char data[], const size_t stride, const size_t n);
double cml_stats_char_skew(const char data[], const size_t stride, const size_t n);
double cml_stats_char_kurtosis(const char data[], const size_t stride, const size_t n);
double cml_stats_char_lag1_autocorrelation(const char data[], const size_t stride, const size_t n);

double cml_stats_char_covariance(const char data1[], const size_t stride1,const char data2[], const size_t stride2, const size_t n);
double cml_stats_char_correlation(const char data1[], const size_t stride1,const char data2[], const size_t stride2, const size_t n);
double cml_stats_char_spearman(const char data1[], const size_t stride1, const char data2[], const size_t stride2, const size_t n, double work[]);

double cml_stats_char_variance_m(const char data[], const size_t stride, const size_t n, const double mean);
double cml_stats_char_sd_m(const char data[], const size_t stride, const size_t n, const double mean);
double cml_stats_char_absdev_m(const char data[], const size_t stride, const size_t n, const double mean);
double cml_stats_char_skew_m_sd(const char data[], const size_t stride, const size_t n, const double mean, const double sd);
double cml_stats_char_kurtosis_m_sd(const char data[], const size_t stride, const size_t n, const double mean, const double sd);
double cml_stats_char_lag1_autocorrelation_m(const char data[], const size_t stride, const size_t n, const double mean);

double cml_stats_char_covariance_m(const char data1[], const size_t stride1,const char data2[], const size_t stride2, const size_t n, const double mean1, const double mean2);


double cml_stats_char_pvariance(const char data1[], const size_t stride1, const size_t n1, const char data2[], const size_t stride2, const size_t n2);
double cml_stats_char_ttest(const char data1[], const size_t stride1, const size_t n1, const char data2[], const size_t stride2, const size_t n2);

char cml_stats_char_max(const char data[], const size_t stride, const size_t n);
char cml_stats_char_min(const char data[], const size_t stride, const size_t n);
void cml_stats_char_minmax(char * min, char * max, const char data[], const size_t stride, const size_t n);

size_t cml_stats_char_max_index(const char data[], const size_t stride, const size_t n);
size_t cml_stats_char_min_index(const char data[], const size_t stride, const size_t n);
void cml_stats_char_minmax_index(size_t * min_index, size_t * max_index, const char data[], const size_t stride, const size_t n);

double cml_stats_char_median_from_sorted_data(const char sorted_data[], const size_t stride, const size_t n);
double cml_stats_char_quantile_from_sorted_data(const char sorted_data[], const size_t stride, const size_t n, const double f);

__CML_END_DECLS

#endif /* CML_STATISTICS_UINT_H */
