#ifndef CML_STATISTICS_H
#error "Never use <cml/statistics/uunsigned char.h> directly; include <cml/statistics.h> instead."
#endif

#ifndef CML_STATISTICS_UINT_H
#define CML_STATISTICS_UINT_H

#include <stdlib.h>

__CML_BEGIN_DECLS

double cml_stats_uchar_mean(const unsigned char data[], const size_t stride, const size_t n);
double cml_stats_uchar_variance(const unsigned char data[], const size_t stride, const size_t n);
double cml_stats_uchar_sd(const unsigned char data[], const size_t stride, const size_t n);
double cml_stats_uchar_variance_with_fixed_mean(const unsigned char data[], const size_t stride, const size_t n, const double mean);
double cml_stats_uchar_sd_with_fixed_mean(const unsigned char data[], const size_t stride, const size_t n, const double mean);
double cml_stats_uchar_tss(const unsigned char data[], const size_t stride, const size_t n);
double cml_stats_uchar_tss_m(const unsigned char data[], const size_t stride, const size_t n, const double mean);

double cml_stats_uchar_absdev(const unsigned char data[], const size_t stride, const size_t n);
double cml_stats_uchar_skew(const unsigned char data[], const size_t stride, const size_t n);
double cml_stats_uchar_kurtosis(const unsigned char data[], const size_t stride, const size_t n);
double cml_stats_uchar_lag1_autocorrelation(const unsigned char data[], const size_t stride, const size_t n);

double cml_stats_uchar_covariance(const unsigned char data1[], const size_t stride1,const unsigned char data2[], const size_t stride2, const size_t n);
double cml_stats_uchar_correlation(const unsigned char data1[], const size_t stride1,const unsigned char data2[], const size_t stride2, const size_t n);
double cml_stats_uchar_spearman(const unsigned char data1[], const size_t stride1, const unsigned char data2[], const size_t stride2, const size_t n, double work[]);

double cml_stats_uchar_variance_m(const unsigned char data[], const size_t stride, const size_t n, const double mean);
double cml_stats_uchar_sd_m(const unsigned char data[], const size_t stride, const size_t n, const double mean);
double cml_stats_uchar_absdev_m(const unsigned char data[], const size_t stride, const size_t n, const double mean);
double cml_stats_uchar_skew_m_sd(const unsigned char data[], const size_t stride, const size_t n, const double mean, const double sd);
double cml_stats_uchar_kurtosis_m_sd(const unsigned char data[], const size_t stride, const size_t n, const double mean, const double sd);
double cml_stats_uchar_lag1_autocorrelation_m(const unsigned char data[], const size_t stride, const size_t n, const double mean);

double cml_stats_uchar_covariance_m(const unsigned char data1[], const size_t stride1,const unsigned char data2[], const size_t stride2, const size_t n, const double mean1, const double mean2);


double cml_stats_uchar_pvariance(const unsigned char data1[], const size_t stride1, const size_t n1, const unsigned char data2[], const size_t stride2, const size_t n2);
double cml_stats_uchar_ttest(const unsigned char data1[], const size_t stride1, const size_t n1, const unsigned char data2[], const size_t stride2, const size_t n2);

unsigned char cml_stats_uchar_max(const unsigned char data[], const size_t stride, const size_t n);
unsigned char cml_stats_uchar_min(const unsigned char data[], const size_t stride, const size_t n);
void cml_stats_uchar_minmax(unsigned char * min, unsigned char * max, const unsigned char data[], const size_t stride, const size_t n);

size_t cml_stats_uchar_max_index(const unsigned char data[], const size_t stride, const size_t n);
size_t cml_stats_uchar_min_index(const unsigned char data[], const size_t stride, const size_t n);
void cml_stats_uchar_minmax_index(size_t * min_index, size_t * max_index, const unsigned char data[], const size_t stride, const size_t n);

double cml_stats_uchar_median_from_sorted_data(const unsigned char sorted_data[], const size_t stride, const size_t n);
double cml_stats_uchar_quantile_from_sorted_data(const unsigned char sorted_data[], const size_t stride, const size_t n, const double f);

__CML_END_DECLS

#endif /* CML_STATISTICS_UINT_H */
