#ifndef CML_VECTOR_H
#error "Never use <cml/vector/minmax.h> directly; include <cml/vector.h> instead."
#endif

#ifndef CML_VECTOR_MINMAX_H
#define CML_VECTOR_MINMAX_H

#include <cml/sort.h>
#include <scic/vector.h>

void *cml_vector_min(vector_t *vector, cml_comparison_fn_t cmp);
void *cml_vector_max(vector_t *vector, cml_comparison_fn_t cmp);

#endif