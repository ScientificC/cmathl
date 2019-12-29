#ifndef CML_SORT_COMMON_H
#define CML_SORT_COMMON_H

__CML_BEGIN_DECLS

typedef int (*cml_comparison_fn_t)(const void *, const void *);

int cml_sort_long_double_cmp(const void *, const void *);
int cml_sort_cmp(const void *, const void *);
int cml_sort_float_cmp(const void *, const void *);

int cml_sort_ulong_cmp(const void *, const void *);
int cml_sort_long_cmp(const void *, const void *);

int cml_sort_uint_cmp(const void *, const void *);
int cml_sort_int_cmp(const void *, const void *);

int cml_sort_ushort_cmp(const void *, const void *);
int cml_sort_short_cmp(const void *, const void *);

int cml_sort_uchar_cmp(const void *, const void *);
int cml_sort_char_cmp(const void *, const void *);

void cml_qsort(void *array, size_t count, size_t size, cml_comparison_fn_t cmp);

void cml_heapsort(void *array, size_t count, size_t size, cml_comparison_fn_t compare);
int cml_heapsort_index(size_t *p, const void *array, size_t count, size_t size, cml_comparison_fn_t compare);

__CML_END_DECLS

#endif
