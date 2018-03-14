#ifndef CML_STATISTICS_H
#error "Never use <cml/statistics/uint.h> directly; include <cml/statistics.h> instead."
#endif

#ifndef CML_STATISTICS_UCHAR_H
#define CML_STATISTICS_UCHAR_H

#include <stdlib.h>

__CML_BEGIN_DECLS

double cml_stats_uint_mean(const unsigned int data[], const size_t stride, const size_t n);
double cml_stats_uint_variance(const unsigned int data[], const size_t stride, const size_t n);
double cml_stats_uint_sd(const unsigned int data[], const size_t stride, const size_t n);
double cml_stats_uint_variance_with_fixed_mean(const unsigned int data[], const size_t stride, const size_t n, const double mean);
double cml_stats_uint_sd_with_fixed_mean(const unsigned int data[], const size_t stride, const size_t n, const double mean);
double cml_stats_uint_tss(const unsigned int data[], const size_t stride, const size_t n);
double cml_stats_uint_tss_m(const unsigned int data[], const size_t stride, const size_t n, const double mean);

double cml_stats_uint_kurtosis(const unsigned int data[], const size_t stride, const size_t n);

double cml_stats_uint_covariance(const unsigned int data1[], const size_t stride1,const unsigned int data2[], const size_t stride2, const size_t n);

double cml_stats_uint_variance_m(const unsigned int data[], const size_t stride, const size_t n, const double mean);
double cml_stats_uint_sd_m(const unsigned int data[], const size_t stride, const size_t n, const double mean);
double cml_stats_uint_kurtosis_m_sd(const unsigned int data[], const size_t stride, const size_t n, const double mean, const double sd);

__CML_END_DECLS

#endif /* CML_STATISTICS_UCHAR_H */
