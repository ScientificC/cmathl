#ifndef CML_BLOCK_H
#error "Never use <cml/block/unsigned_long.h> directly; include <cml/block.h> instead."
#endif

#ifndef CML_BLOCK_ULONG_H
#define CML_BLOCK_ULONG_H

#include <stdlib.h>
#include <stdio.h>

__CML_BEGIN_DECLS

typedef struct
{
        size_t size;
        unsigned long *data;
} cml_block_ulong_t;


cml_block_ulong_t *cml_block_ulong_alloc(const size_t n);
cml_block_ulong_t *cml_block_ulong_calloc(const size_t n);
void cml_block_ulong_free(cml_block_ulong_t *b);

int cml_block_ulong_fread(FILE *stream, cml_block_ulong_t *b);
int cml_block_ulong_fwrite(FILE *stream, const cml_block_ulong_t *b);
int cml_block_ulong_fscanf(FILE *stream, cml_block_ulong_t *b);
int cml_block_ulong_fprunsigned_longf(FILE *stream, const cml_block_ulong_t *b, const char *format);

int cml_block_ulong_raw_fread(FILE *stream, unsigned long *b, const size_t n, const size_t stride);
int cml_block_ulong_raw_fwrite(FILE *stream, const unsigned long *b, const size_t n, const size_t stride);
int cml_block_ulong_raw_fscanf(FILE *stream, unsigned long *b, const size_t n, const size_t stride);
int cml_block_ulong_raw_fprunsigned_longf(FILE *stream, const unsigned long *b, const size_t n, const size_t stride, const char *format);

size_t cml_block_ulong_size(const cml_block_ulong_t *b);
unsigned long * cml_block_ulong_data(const cml_block_ulong_t *b);

__CML_END_DECLS

#endif /* CML_BLOCK_ULONG_H */
