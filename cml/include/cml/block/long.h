#ifndef CML_BLOCK_H
#error "Never use <cml/block/long.h> directly; include <cml/block.h> instead."
#endif

#ifndef CML_BLOCK_LONG_H
#define CML_BLOCK_LONG_H

#include <stdlib.h>
#include <stdio.h>

__CML_BEGIN_DECLS

typedef struct
{
        size_t size;
        long *data;
} cml_block_long_t;


cml_block_long_t *cml_block_long_alloc(const size_t n);
cml_block_long_t *cml_block_long_calloc(const size_t n);
void cml_block_long_free(cml_block_long_t *b);

int cml_block_long_fread(FILE *stream, cml_block_long_t *b);
int cml_block_long_fwrite(FILE *stream, const cml_block_long_t *b);
int cml_block_long_fscanf(FILE *stream, cml_block_long_t *b);
int cml_block_long_fprlongf(FILE *stream, const cml_block_long_t *b, const long *format);

int cml_block_long_raw_fread(FILE *stream, long *b, const size_t n, const size_t stride);
int cml_block_long_raw_fwrite(FILE *stream, const long *b, const size_t n, const size_t stride);
int cml_block_long_raw_fscanf(FILE *stream, long *b, const size_t n, const size_t stride);
int cml_block_long_raw_fprlongf(FILE *stream, const long *b, const size_t n, const size_t stride, const long *format);

size_t cml_block_long_size(const cml_block_long_t *b);
long * cml_block_long_data(const cml_block_long_t *b);

__CML_END_DECLS

#endif /* CML_BLOCK_LONG_H */
