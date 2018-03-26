#ifndef CML_BLOCK_H
#error "Never use <cml/block/int.h> directly; include <cml/block.h> instead."
#endif

#ifndef CML_BLOCK_INT_H
#define CML_BLOCK_INT_H

#include <stdlib.h>
#include <stdio.h>

__CML_BEGIN_DECLS

typedef struct
{
        size_t size;
        int *data;
} cml_block_int_t;


cml_block_int_t *cml_block_int_alloc(const size_t n);
cml_block_int_t *cml_block_int_calloc(const size_t n);
void cml_block_int_free(cml_block_int_t *b);

int cml_block_int_fread(FILE *stream, cml_block_int_t *b);
int cml_block_int_fwrite(FILE *stream, const cml_block_int_t *b);
int cml_block_int_fscanf(FILE *stream, cml_block_int_t *b);
int cml_block_int_fprintf(FILE *stream, const cml_block_int_t *b, const char *format);

int cml_block_int_raw_fread(FILE *stream, int *b, const size_t n, const size_t stride);
int cml_block_int_raw_fwrite(FILE *stream, const int *b, const size_t n, const size_t stride);
int cml_block_int_raw_fscanf(FILE *stream, int *b, const size_t n, const size_t stride);
int cml_block_int_raw_fprintf(FILE *stream, const int *b, const size_t n, const size_t stride, const char *format);

size_t cml_block_int_size(const cml_block_int_t *b);
int * cml_block_int_data(const cml_block_int_t *b);

__CML_END_DECLS

#endif /* CML_BLOCK_INT_H */
