#ifndef CML_BLOCK_H
#error "Never use <cml/block/double.h> directly; include <cml/block.h> instead."
#endif

#ifndef CML_BLOCK_DOUBLE_H
#define CML_BLOCK_DOUBLE_H

#include <stdlib.h>
#include <stdio.h>

__CML_BEGIN_DECLS

typedef struct
{
        size_t size;
        double *data;
} cml_block_t;


cml_block_t *cml_block_alloc(const size_t n);
cml_block_t *cml_block_calloc(const size_t n);
void cml_block_free(cml_block_t *b);

int cml_block_fread(FILE *stream, cml_block_t *b);
int cml_block_fwrite(FILE *stream, const cml_block_t *b);
int cml_block_fscanf(FILE *stream, cml_block_t *b);
int cml_block_fprintf(FILE *stream, const cml_block_t *b, const char *format);

int cml_block_raw_fread(FILE *stream, double *b, const size_t n, const size_t stride);
int cml_block_raw_fwrite(FILE *stream, const double *b, const size_t n, const size_t stride);
int cml_block_raw_fscanf(FILE *stream, double *b, const size_t n, const size_t stride);
int cml_block_raw_fprintf(FILE *stream, const double *b, const size_t n, const size_t stride, const char *format);

size_t cml_block_size(const cml_block_t *b);
double * cml_block_data(const cml_block_t *b);

__CML_END_DECLS

#endif /* CML_BLOCK_DOUBLE_H */
