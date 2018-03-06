#ifndef CML_H
#error "Never use <cml/block/ushort.h> directly; include <cml/block.h> instead."
#endif

#ifndef CML_BLOCK_USHORT_H
#define CML_BLOCK_USHORT_H

#include <stdlib.h>
#include <stdio.h>

__CML_BEGIN_DECLS

typedef struct
{
        size_t size;
        unsigned short *data;
} cml_block_ushort_t;


cml_block_ushort_t *cml_block_ushort_alloc(const size_t n);
cml_block_ushort_t *cml_block_ushort_calloc(const size_t n);
void cml_block_ushort_free(cml_block_ushort_t *b);

int cml_block_ushort_fread(FILE *stream, cml_block_ushort_t *b);
int cml_block_ushort_fwrite(FILE *stream, const cml_block_ushort_t *b);
int cml_block_ushort_fscanf(FILE *stream, cml_block_ushort_t *b);
int cml_block_ushort_fprushortf(FILE *stream, const cml_block_ushort_t *b, const unsigned short *format);

int cml_block_ushort_raw_fread(FILE *stream, unsigned short *b, const size_t n, const size_t stride);
int cml_block_ushort_raw_fwrite(FILE *stream, const unsigned short *b, const size_t n, const size_t stride);
int cml_block_ushort_raw_fscanf(FILE *stream, unsigned short *b, const size_t n, const size_t stride);
int cml_block_ushort_raw_fprushortf(FILE *stream, const unsigned short *b, const size_t n, const size_t stride, const unsigned short *format);

size_t cml_block_ushort_size(const cml_block_ushort_t *b);
unsigned short * cml_block_ushort_data(const cml_block_ushort_t *b);

__CML_END_DECLS

#endif /* CML_BLOCK_USHORT_H */
