#ifndef CML_BLOCK_H
#error "Never use <cml/block/quaternion_float.h> directly; include <cml/block.h> instead."
#endif

#ifndef CML_BLOCK_QUATERNION_FLOAT_H
#define CML_BLOCK_QUATERNION_FLOAT_H

#include <stdlib.h>
#include <stdio.h>

__CML_BEGIN_DECLS

typedef struct
{
        size_t size;
        float *data;
} cml_block_quaternion_float_t;


cml_block_quaternion_float_t *cml_block_quaternion_float_alloc(const size_t n);
cml_block_quaternion_float_t *cml_block_quaternion_float_calloc(const size_t n);
void cml_block_quaternion_float_free(cml_block_quaternion_float_t *b);

int cml_block_quaternion_float_fread(FILE *stream, cml_block_quaternion_float_t *b);
int cml_block_quaternion_float_fwrite(FILE *stream, const cml_block_quaternion_float_t *b);
int cml_block_quaternion_float_fscanf(FILE *stream, cml_block_quaternion_float_t *b);
int cml_block_quaternion_float_fprintf(FILE *stream, const cml_block_quaternion_float_t *b, const char *format);

int cml_block_quaternion_float_raw_fread(FILE *stream, float *b, const size_t n, const size_t stride);
int cml_block_quaternion_float_raw_fwrite(FILE *stream, const float *b, const size_t n, const size_t stride);
int cml_block_quaternion_float_raw_fscanf(FILE *stream, float *b, const size_t n, const size_t stride);
int cml_block_quaternion_float_raw_fprintf(FILE *stream, const float *b, const size_t n, const size_t stride, const char *format);

size_t cml_block_quaternion_float_size(const cml_block_quaternion_float_t *b);
float * cml_block_quaternion_float_data(const cml_block_quaternion_float_t *b);

__CML_END_DECLS

#endif /* CML_BLOCK_QUATERNION_FLOAT_H */
