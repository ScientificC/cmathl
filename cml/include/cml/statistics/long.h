#ifndef CML_STATISTICS_H
#error "Never use <cml/statistics/long.h> directly; include <cml/statistics.h> instead."
#endif

#ifndef CML_STATISTICS_LONG_H
#define CML_STATISTICS_LONG_H

#include <stdlib.h>

__CML_BEGIN_DECLS

double cml_stats_long_mean(const long data[], const size_t stride, const size_t n);
double cml_stats_long_variance(const long data[], const size_t stride, const size_t n);
double cml_stats_long_sd(const long data[], const size_t stride, const size_t n);
double cml_stats_long_variance_with_fixed_mean(const long data[], const size_t stride, const size_t n, const double mean);
double cml_stats_long_sd_with_fixed_mean(const long data[], const size_t stride, const size_t n, const double mean);
double cml_stats_long_tss(const long data[], const size_t stride, const size_t n);
double cml_stats_long_tss_m(const long data[], const size_t stride, const size_t n, const double mean);

double cml_stats_long_kurtosis(const long data[], const size_t stride, const size_t n);

double cml_stats_long_covariance(const long data1[], const size_t stride1,const long data2[], const size_t stride2, const size_t n);

double cml_stats_long_variance_m(const long data[], const size_t stride, const size_t n, const double mean);
double cml_stats_long_sd_m(const long data[], const size_t stride, const size_t n, const double mean);
double cml_stats_long_kurtosis_m_sd(const long data[], const size_t stride, const size_t n, const double mean, const double sd);

__CML_END_DECLS

#endif /* CML_STATISTICS_LONG_H */
