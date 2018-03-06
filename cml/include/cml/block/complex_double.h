#ifndef CML_H
#error "Never use <cml/block/complex_double.h> directly; include <cml/block.h> instead."
#endif

#ifndef CML_BLOCK_COMPLEX_H
#define CML_BLOCK_COMPLEX_H

#include <stdlib.h>
#include <stdio.h>

__CML_BEGIN_DECLS

typedef struct
{
        size_t size;
        double *data;
} cml_block_complex_t;


cml_block_complex_t *cml_block_complex_alloc(const size_t n);
cml_block_complex_t *cml_block_complex_calloc(const size_t n);
void cml_block_complex_free(cml_block_complex_t *b);

int cml_block_complex_fread(FILE *stream, cml_block_complex_t *b);
int cml_block_complex_fwrite(FILE *stream, const cml_block_complex_t *b);
int cml_block_complex_fscanf(FILE *stream, cml_block_complex_t *b);
int cml_block_complex_fprintf(FILE *stream, const cml_block_complex_t *b, const double *format);

int cml_block_complex_raw_fread(FILE *stream, double *b, const size_t n, const size_t stride);
int cml_block_complex_raw_fwrite(FILE *stream, const double *b, const size_t n, const size_t stride);
int cml_block_complex_raw_fscanf(FILE *stream, double *b, const size_t n, const size_t stride);
int cml_block_complex_raw_fprintf(FILE *stream, const double *b, const size_t n, const size_t stride, const double *format);

size_t cml_block_complex_size(const cml_block_complex_t *b);
double * cml_block_complex_data(const cml_block_complex_t *b);

__CML_END_DECLS

#endif /* CML_BLOCK_COMPLEX_H */
