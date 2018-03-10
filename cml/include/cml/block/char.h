#ifndef CML_BLOCK_H
#error "Never use <cml/block/char.h> directly; include <cml/block.h> instead."
#endif

#ifndef CML_BLOCK_CHAR_H
#define CML_BLOCK_CHAR_H

#include <stdlib.h>
#include <stdio.h>

__CML_BEGIN_DECLS

typedef struct
{
        size_t size;
        char *data;
} cml_block_char_t;


cml_block_char_t *cml_block_char_alloc(const size_t n);
cml_block_char_t *cml_block_char_calloc(const size_t n);
void cml_block_char_free(cml_block_char_t *b);

int cml_block_char_fread(FILE *stream, cml_block_char_t *b);
int cml_block_char_fwrite(FILE *stream, const cml_block_char_t *b);
int cml_block_char_fscanf(FILE *stream, cml_block_char_t *b);
int cml_block_char_fprintf(FILE *stream, const cml_block_char_t *b, const char *format);

int cml_block_char_raw_fread(FILE *stream, char *b, const size_t n, const size_t stride);
int cml_block_char_raw_fwrite(FILE *stream, const char *b, const size_t n, const size_t stride);
int cml_block_char_raw_fscanf(FILE *stream, char *b, const size_t n, const size_t stride);
int cml_block_char_raw_fprintf(FILE *stream, const char *b, const size_t n, const size_t stride, const char *format);

size_t cml_block_char_size(const cml_block_char_t *b);
char * cml_block_char_data(const cml_block_char_t *b);

__CML_END_DECLS

#endif /* CML_BLOCK_CHAR_H */
