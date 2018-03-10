#ifndef CML_BLOCK_H
#error "Never use <cml/block/uint.h> directly; include <cml/block.h> instead."
#endif

#ifndef CML_BLOCK_UCHAR_H
#define CML_BLOCK_UCHAR_H

#include <stdlib.h>
#include <stdio.h>

__CML_BEGIN_DECLS

typedef struct
{
        size_t size;
        unsigned int *data;
} cml_block_uint_t;


cml_block_uint_t *cml_block_uint_alloc(const size_t n);
cml_block_uint_t *cml_block_uint_calloc(const size_t n);
void cml_block_uint_free(cml_block_uint_t *b);

int cml_block_uint_fread(FILE *stream, cml_block_uint_t *b);
int cml_block_uint_fwrite(FILE *stream, const cml_block_uint_t *b);
int cml_block_uint_fscanf(FILE *stream, cml_block_uint_t *b);
int cml_block_uint_fpruintf(FILE *stream, const cml_block_uint_t *b, const unsigned int *format);

int cml_block_uint_raw_fread(FILE *stream, unsigned int *b, const size_t n, const size_t stride);
int cml_block_uint_raw_fwrite(FILE *stream, const unsigned int *b, const size_t n, const size_t stride);
int cml_block_uint_raw_fscanf(FILE *stream, unsigned int *b, const size_t n, const size_t stride);
int cml_block_uint_raw_fpruintf(FILE *stream, const unsigned int *b, const size_t n, const size_t stride, const unsigned int *format);

size_t cml_block_uint_size(const cml_block_uint_t *b);
unsigned int * cml_block_uint_data(const cml_block_uint_t *b);

__CML_END_DECLS

#endif /* CML_BLOCK_UCHAR_H */
