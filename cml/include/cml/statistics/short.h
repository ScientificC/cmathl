#ifndef CML_STATISTICS_H
#error "Never use <cml/statistics/short.h> directly; include <cml/statistics.h> instead."
#endif

#ifndef CML_STATISTICS_SHORT_H
#define CML_STATISTICS_SHORT_H

#include <stdlib.h>

__CML_BEGIN_DECLS

double cml_stats_short_mean(const short data[], const size_t stride, const size_t n);
double cml_stats_short_variance(const short data[], const size_t stride, const size_t n);
double cml_stats_short_sd(const short data[], const size_t stride, const size_t n);
double cml_stats_short_variance_with_fixed_mean(const short data[], const size_t stride, const size_t n, const double mean);
double cml_stats_short_sd_with_fixed_mean(const short data[], const size_t stride, const size_t n, const double mean);
double cml_stats_short_tss(const short data[], const size_t stride, const size_t n);
double cml_stats_short_tss_m(const short data[], const size_t stride, const size_t n, const double mean);

double cml_stats_short_absdev(const short data[], const size_t stride, const size_t n);
double cml_stats_short_skew(const short data[], const size_t stride, const size_t n);
double cml_stats_short_kurtosis(const short data[], const size_t stride, const size_t n);
double cml_stats_short_lag1_autocorrelation(const short data[], const size_t stride, const size_t n);

double cml_stats_short_covariance(const short data1[], const size_t stride1,const short data2[], const size_t stride2, const size_t n);
double cml_stats_short_correlation(const short data1[], const size_t stride1,const short data2[], const size_t stride2, const size_t n);
double cml_stats_short_spearman(const short data1[], const size_t stride1, const short data2[], const size_t stride2, const size_t n, double work[]);

double cml_stats_short_variance_m(const short data[], const size_t stride, const size_t n, const double mean);
double cml_stats_short_sd_m(const short data[], const size_t stride, const size_t n, const double mean);
double cml_stats_short_absdev_m(const short data[], const size_t stride, const size_t n, const double mean);
double cml_stats_short_skew_m_sd(const short data[], const size_t stride, const size_t n, const double mean, const double sd);
double cml_stats_short_kurtosis_m_sd(const short data[], const size_t stride, const size_t n, const double mean, const double sd);
double cml_stats_short_lag1_autocorrelation_m(const short data[], const size_t stride, const size_t n, const double mean);

double cml_stats_short_covariance_m(const short data1[], const size_t stride1,const short data2[], const size_t stride2, const size_t n, const double mean1, const double mean2);


double cml_stats_short_pvariance(const short data1[], const size_t stride1, const size_t n1, const short data2[], const size_t stride2, const size_t n2);
double cml_stats_short_ttest(const short data1[], const size_t stride1, const size_t n1, const short data2[], const size_t stride2, const size_t n2);

short cml_stats_short_max(const short data[], const size_t stride, const size_t n);
short cml_stats_short_min(const short data[], const size_t stride, const size_t n);
void cml_stats_short_minmax(short * min, short * max, const short data[], const size_t stride, const size_t n);

size_t cml_stats_short_max_index(const short data[], const size_t stride, const size_t n);
size_t cml_stats_short_min_index(const short data[], const size_t stride, const size_t n);
void cml_stats_short_minmax_index(size_t * min_index, size_t * max_index, const short data[], const size_t stride, const size_t n);

double cml_stats_short_median_from_sorted_data(const short sorted_data[], const size_t stride, const size_t n);
double cml_stats_short_quantile_from_sorted_data(const short sorted_data[], const size_t stride, const size_t n, const double f);

__CML_END_DECLS

#endif /* CML_STATISTICS_SHORT_H */
