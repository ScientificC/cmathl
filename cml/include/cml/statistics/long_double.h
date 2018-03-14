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

double cml_stats_long_double_kurtosis(const long double data[], const size_t stride, const size_t n);

double cml_stats_long_double_covariance(const long double data1[], const size_t stride1, const long double data2[], const size_t stride2, const size_t n);

double cml_stats_long_double_variance_m(const long double data[], const size_t stride, const size_t n, const double mean);
double cml_stats_long_double_sd_m(const long double data[], const size_t stride, const size_t n, const double mean);
double cml_stats_long_double_kurtosis_m_sd(const long double data[], const size_t stride, const size_t n, const double mean, const double sd);

__CML_END_DECLS

#endif /* CML_STATISTICS_LONG_DOUBLE_H */
