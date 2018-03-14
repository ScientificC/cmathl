#ifndef CML_STATISTICS_H
#error "Never use <cml/statistics/uchar.h> directly; include <cml/statistics.h> instead."
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

double cml_stats_uchar_kurtosis(const unsigned char data[], const size_t stride, const size_t n);

double cml_stats_uchar_covariance(const unsigned char data1[], const size_t stride1,const unsigned char data2[], const size_t stride2, const size_t n);

double cml_stats_uchar_variance_m(const unsigned char data[], const size_t stride, const size_t n, const double mean);
double cml_stats_uchar_sd_m(const unsigned char data[], const size_t stride, const size_t n, const double mean);
double cml_stats_uchar_kurtosis_m_sd(const unsigned char data[], const size_t stride, const size_t n, const double mean, const double sd);

__CML_END_DECLS

#endif /* CML_STATISTICS_UINT_H */
