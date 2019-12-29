#ifndef CML_VECTOR_H
#error "Never use <cml/vector/minmax.h> directly; include <cml/vector.h> instead."
#endif

#ifndef CML_VECTOR_MINMAX_H
#define CML_VECTOR_MINMAX_H

#include <cml/sort.h>
#include <scic/vector.h>

void *cml_vector_min(vector_t *vector, cml_comparison_fn_t cmp);
void *cml_vector_max(vector_t *vector, cml_comparison_fn_t cmp);

vector_t cml_vector_minmax(vector_t *vector, cml_comparison_fn_t cmp);

/* Min function macros */

#define cml_vector_min_as(type, vector_ptr, cmp_ptr) (*((type *) cml_vector_min(vector_ptr, cmp_ptr)))

#define cml_vector_min_as_long_double(...) cml_vector_min_as(long double, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_long_double_cmp)
#define cml_vector_min_as_double(...) cml_vector_min_as(double, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_cmp)
#define cml_vector_min_as_float(...) cml_vector_min_as(float, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_float_cmp)

#define cml_vector_min_as_ulong(...) cml_vector_min_as(unsigned long, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_ulong_cmp)
#define cml_vector_min_as_long(...) cml_vector_min_as(long, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_long_cmp)

#define cml_vector_min_as_uint(...) cml_vector_min_as(unsigned, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_uint_cmp)
#define cml_vector_min_as_int(...) cml_vector_min_as(int, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_int_cmp)

#define cml_vector_min_as_ushort(...) cml_vector_min_as(unsigned short, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_ushort_cmp)
#define cml_vector_min_as_short(...) cml_vector_min_as(short, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_short_cmp)

#define cml_vector_min_as_uchar(...) cml_vector_min_as(unsigned char, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_uchar_cmp)
#define cml_vector_min_as_char(...) cml_vector_min_as(char, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_char_cmp)


/* Max function macros */

#define cml_vector_max_as(type, vector_ptr, cmp_ptr) (*((type *) cml_vector_max(vector_ptr, cmp_ptr)))

#define cml_vector_max_as_long_double(...) cml_vector_max_as(long double, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_long_double_cmp)
#define cml_vector_max_as_double(...) cml_vector_max_as(double, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_cmp)
#define cml_vector_max_as_float(...) cml_vector_max_as(float, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_float_cmp)

#define cml_vector_max_as_ulong(...) cml_vector_max_as(unsigned long, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_ulong_cmp)
#define cml_vector_max_as_long(...) cml_vector_max_as(long, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_long_cmp)

#define cml_vector_max_as_uint(...) cml_vector_max_as(unsigned, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_uint_cmp)
#define cml_vector_max_as_int(...) cml_vector_max_as(int, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_int_cmp)

#define cml_vector_max_as_ushort(...) cml_vector_max_as(unsigned short, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_ushort_cmp)
#define cml_vector_max_as_short(...) cml_vector_max_as(short, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_short_cmp)

#define cml_vector_max_as_uchar(...) cml_vector_max_as(unsigned char, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_uchar_cmp)
#define cml_vector_max_as_char(...) cml_vector_max_as(char, __CML_ARGS_FIRST(__VA_ARGS__), &cml_sort_char_cmp)

#endif