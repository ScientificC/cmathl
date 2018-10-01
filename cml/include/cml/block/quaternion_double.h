#ifndef CML_BLOCK_H
#error "Never use <cml/block/quaternion_double.h> directly; include <cml/block.h> instead."
#endif

#ifndef CML_BLOCK_QUATERNION_DOUBLE_H
#define CML_BLOCK_QUATERNION_DOUBLE_H

#include <stdlib.h>
#include <stdio.h>

__CML_BEGIN_DECLS

typedef struct
{
        size_t size;
        double *data;
} cml_block_quaternion_t;


cml_block_quaternion_t *cml_block_quaternion_alloc(const size_t n);
cml_block_quaternion_t *cml_block_quaternion_calloc(const size_t n);
void cml_block_quaternion_free(cml_block_quaternion_t *b);

int cml_block_quaternion_fread(FILE *stream, cml_block_quaternion_t *b);
int cml_block_quaternion_fwrite(FILE *stream, const cml_block_quaternion_t *b);
int cml_block_quaternion_fscanf(FILE *stream, cml_block_quaternion_t *b);
int cml_block_quaternion_fprintf(FILE *stream, const cml_block_quaternion_t *b, const char *format);

int cml_block_quaternion_raw_fread(FILE *stream, double *b, const size_t n, const size_t stride);
int cml_block_quaternion_raw_fwrite(FILE *stream, const double *b, const size_t n, const size_t stride);
int cml_block_quaternion_raw_fscanf(FILE *stream, double *b, const size_t n, const size_t stride);
int cml_block_quaternion_raw_fprintf(FILE *stream, const double *b, const size_t n, const size_t stride, const char *format);

size_t cml_block_quaternion_size(const cml_block_quaternion_t *b);
double *cml_block_quaternion_data(const cml_block_quaternion_t *b);

__CML_END_DECLS

#endif /* CML_BLOCK_QUATERNION_DOUBLE_H */
