#ifndef CML_STATISTICS_H
#error "Never use <cml/statistics/ushort.h> directly; include <cml/statistics.h> instead."
#endif

#ifndef CML_STATISTICS_USHORT_H
#define CML_STATISTICS_USHORT_H

#include <stdlib.h>

__CML_BEGIN_DECLS

double cml_stats_ushort_mean(const unsigned short data[], const size_t stride, const size_t n);
double cml_stats_ushort_variance(const unsigned short data[], const size_t stride, const size_t n);
double cml_stats_ushort_sd(const unsigned short data[], const size_t stride, const size_t n);
double cml_stats_ushort_variance_with_fixed_mean(const unsigned short data[], const size_t stride, const size_t n, const double mean);
double cml_stats_ushort_sd_with_fixed_mean(const unsigned short data[], const size_t stride, const size_t n, const double mean);
double cml_stats_ushort_tss(const unsigned short data[], const size_t stride, const size_t n);
double cml_stats_ushort_tss_m(const unsigned short data[], const size_t stride, const size_t n, const double mean);

double cml_stats_ushort_covariance(const unsigned short data1[], const size_t stride1,const unsigned short data2[], const size_t stride2, const size_t n);

double cml_stats_ushort_variance_m(const unsigned short data[], const size_t stride, const size_t n, const double mean);
double cml_stats_ushort_sd_m(const unsigned short data[], const size_t stride, const size_t n, const double mean);

__CML_END_DECLS

#endif /* CML_STATISTICS_USHORT_H */
