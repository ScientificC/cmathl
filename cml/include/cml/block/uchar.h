#ifndef CML_H
#error "Never use <cml/block/uchar.h> directly; include <cml/block.h> instead."
#endif

#ifndef CML_BLOCK_UINT_H
#define CML_BLOCK_UINT_H

#include <stdlib.h>
#include <stdio.h>

__CML_BEGIN_DECLS

typedef struct
{
        size_t size;
        unsigned char *data;
} cml_block_uchar_t;


cml_block_uchar_t *cml_block_uchar_alloc(const size_t n);
cml_block_uchar_t *cml_block_uchar_calloc(const size_t n);
void cml_block_uchar_free(cml_block_uchar_t *b);

int cml_block_uchar_fread(FILE *stream, cml_block_uchar_t *b);
int cml_block_uchar_fwrite(FILE *stream, const cml_block_uchar_t *b);
int cml_block_uchar_fscanf(FILE *stream, cml_block_uchar_t *b);
int cml_block_uchar_fprucharf(FILE *stream, const cml_block_uchar_t *b, const unsigned char *format);

int cml_block_uchar_raw_fread(FILE *stream, unsigned char *b, const size_t n, const size_t stride);
int cml_block_uchar_raw_fwrite(FILE *stream, const unsigned char *b, const size_t n, const size_t stride);
int cml_block_uchar_raw_fscanf(FILE *stream, unsigned char *b, const size_t n, const size_t stride);
int cml_block_uchar_raw_fprucharf(FILE *stream, const unsigned char *b, const size_t n, const size_t stride, const unsigned char *format);

size_t cml_block_uchar_size(const cml_block_uchar_t *b);
unsigned char * cml_block_uchar_data(const cml_block_uchar_t *b);

__CML_END_DECLS

#endif /* CML_BLOCK_UINT_H */
