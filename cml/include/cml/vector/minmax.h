#ifndef CML_VECTOR_H
#error "Never use <cml/vector/minmax.h> directly; include <cml/vector.h> instead."
#endif

#ifndef CML_VECTOR_MINMAX_H
#define CML_VECTOR_MINMAX_H

#include <cml/sort.h>
#include <scic/vector.h>

void *cml_vector_min(vector_t *vector, cml_comparison_fn_t cmp);
void *cml_vector_max(vector_t *vector, cml_comparison_fn_t cmp);

vector_t *cml_vector_minmax(vector_t *vector, cml_comparison_fn_t min_cmp, cml_comparison_fn_t max_cmp);

#define cml_vector_min_as(type, vector_ptr, cmp_ptr) (*((type *) cml_vector_min(vector_ptr, cmp_ptr)))
#define cml_vector_max_as(type, vector_ptr, cmp_ptr) (*((type *) cml_vector_max(vector_ptr, cmp_ptr)))

#endif