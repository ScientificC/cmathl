#ifndef CML_BLOCK_H
#error "Never use <cml/block/short.h> directly; include <cml/block.h> instead."
#endif

#ifndef CML_BLOCK_SHORT_H
#define CML_BLOCK_SHORT_H

#include <stdlib.h>
#include <stdio.h>

__CML_BEGIN_DECLS

typedef struct
{
        size_t size;
        short *data;
} cml_block_short_t;


cml_block_short_t *cml_block_short_alloc(const size_t n);
cml_block_short_t *cml_block_short_calloc(const size_t n);
void cml_block_short_free(cml_block_short_t *b);

int cml_block_short_fread(FILE *stream, cml_block_short_t *b);
int cml_block_short_fwrite(FILE *stream, const cml_block_short_t *b);
int cml_block_short_fscanf(FILE *stream, cml_block_short_t *b);
int cml_block_short_fprshortf(FILE *stream, const cml_block_short_t *b, const short *format);

int cml_block_short_raw_fread(FILE *stream, short *b, const size_t n, const size_t stride);
int cml_block_short_raw_fwrite(FILE *stream, const short *b, const size_t n, const size_t stride);
int cml_block_short_raw_fscanf(FILE *stream, short *b, const size_t n, const size_t stride);
int cml_block_short_raw_fprshortf(FILE *stream, const short *b, const size_t n, const size_t stride, const short *format);

size_t cml_block_short_size(const cml_block_short_t *b);
short * cml_block_short_data(const cml_block_short_t *b);

__CML_END_DECLS

#endif /* CML_BLOCK_SHORT_H */
