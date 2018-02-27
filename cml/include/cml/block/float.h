#ifndef CML_H
#error "Never use <cml/block/float.h> directly; include <cml/block.h> instead."
#endif

#ifndef CML_BLOCK_FLOAT_H
#define CML_BLOCK_FLOAT_H

#include <stdlib.h>
#include <stdio.h>

__BEGIN_DECLS

typedef struct
{
        size_t size;
        float *data;
} cml_block_float_t;


cml_block_float_t *cml_block_float_alloc(const size_t n);
cml_block_float_t *cml_block_float_calloc(const size_t n);
void cml_block_float_free(cml_block_float_t *b);

int cml_block_float_fread(FILE *stream, cml_block_float_t *b);
int cml_block_float_fwrite(FILE *stream, const cml_block_float_t *b);
int cml_block_float_fscanf(FILE *stream, cml_block_float_t *b);
int cml_block_float_fprintf(FILE *stream, const cml_block_float_t *b, const float *format);

int cml_block_float_raw_fread(FILE *stream, float *b, const size_t n, const size_t stride);
int cml_block_float_raw_fwrite(FILE *stream, const float *b, const size_t n, const size_t stride);
int cml_block_float_raw_fscanf(FILE *stream, float *b, const size_t n, const size_t stride);
int cml_block_float_raw_fprintf(FILE *stream, const float *b, const size_t n, const size_t stride, const float *format);

size_t cml_block_float_size(const cml_block_float_t *b);
float * cml_block_float_data(const cml_block_float_t *b);

__END_DECLS

#endif /* CML_BLOCK_FLOAT_H */
