#ifndef CML_THREADS_H
#define CML_THREADS_H

typedef struct _block {
        void **argv;
        void *(*function)(void *, ...);
} block_t;

block_t block_create(void *(*)(void *, ...), void **);
void block_destroy(block_t *);

#endif
