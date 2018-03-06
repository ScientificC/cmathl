#ifndef CML_H
#error "Never use <cml/block/long_double.h> directly; include <cml/block.h> instead."
#endif

#ifndef CML_BLOCK_LONG_DOUBLE_H
#define CML_BLOCK_LONG_DOUBLE_H

#include <stdlib.h>
#include <stdio.h>

__CML_BEGIN_DECLS

typedef struct
{
        size_t size;
        long double *data;
} cml_block_long_double_t;


cml_block_long_double_t *cml_block_long_double_alloc(const size_t n);
cml_block_long_double_t *cml_block_long_double_calloc(const size_t n);
void cml_block_long_double_free(cml_block_long_double_t *b);

int cml_block_long_double_fread(FILE *stream, cml_block_long_double_t *b);
int cml_block_long_double_fwrite(FILE *stream, const cml_block_long_double_t *b);
int cml_block_long_double_fscanf(FILE *stream, cml_block_long_double_t *b);
int cml_block_long_double_fprintf(FILE *stream, const cml_block_long_double_t *b, const long double *format);

int cml_block_long_double_raw_fread(FILE *stream, long double *b, const size_t n, const size_t stride);
int cml_block_long_double_raw_fwrite(FILE *stream, const long double *b, const size_t n, const size_t stride);
int cml_block_long_double_raw_fscanf(FILE *stream, long double *b, const size_t n, const size_t stride);
int cml_block_long_double_raw_fprintf(FILE *stream, const long double *b, const size_t n, const size_t stride, const long double *format);

size_t cml_block_long_double_size(const cml_block_long_double_t *b);
long double * cml_block_long_double_data(const cml_block_long_double_t *b);

__CML_END_DECLS

#endif /* CML_BLOCK_LONG_DOUBLE_H */
