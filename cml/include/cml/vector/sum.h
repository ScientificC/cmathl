#ifndef CML_VECTOR_H
#error "Never use <cml/vector/sum.h> directly; include <cml/vector.h> instead."
#endif

#ifndef CML_VECTOR_MINMAX_H
#define CML_VECTOR_MINMAX_H

#include <cml/sort.h>
#include <scic/vector.h>


/* Sum function macros */

long double cml_vector_sum_as_long_double(vector_t *vector);
double cml_vector_sum_as_double(vector_t *vector);
float cml_vector_sum_as_float(vector_t *vector);

unsigned long cml_vector_sum_as_ulong(vector_t *vector);
long cml_vector_sum_as_long(vector_t *vector);

unsigned int cml_vector_sum_as_uint(vector_t *vector);
int cml_vector_sum_as_int(vector_t *vector);

unsigned short cml_vector_sum_as_ushort(vector_t *vector);
short cml_vector_sum_as_short(vector_t *vector);

unsigned char cml_vector_sum_as_uchar(vector_t *vector);
char cml_vector_sum_as_char(vector_t *vector);

#endif