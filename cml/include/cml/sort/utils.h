#ifndef CML_SORT_COMMON_H
#define CML_SORT_COMMON_H

__CML_BEGIN_DECLS

typedef int (*cml_comparison_fn_t)(const void *, const void *);

void cml_qsort(void *a, size_t n, size_t es, cml_comparison_fn_t cmp);

void cml_heapsort(void * array, size_t count, size_t size, cml_comparison_fn_t compare);
int cml_heapsort_index(size_t * p, const void * array, size_t count, size_t size, cml_comparison_fn_t compare);

__CML_END_DECLS

#endif
