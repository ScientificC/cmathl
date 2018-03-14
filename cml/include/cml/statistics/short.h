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

double cml_stats_short_kurtosis(const short data[], const size_t stride, const size_t n);

double cml_stats_short_covariance(const short data1[], const size_t stride1,const short data2[], const size_t stride2, const size_t n);

double cml_stats_short_variance_m(const short data[], const size_t stride, const size_t n, const double mean);
double cml_stats_short_sd_m(const short data[], const size_t stride, const size_t n, const double mean);
double cml_stats_short_kurtosis_m_sd(const short data[], const size_t stride, const size_t n, const double mean, const double sd);

__CML_END_DECLS

#endif /* CML_STATISTICS_SHORT_H */
