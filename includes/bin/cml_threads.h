#ifndef CML_THREADS_H
#define CML_THREADS_H

#define MAXLOOPS 100000
#define MAXTHREADS 10

typedef struct _block {
        int from;
        int delta;
        void **argv;
        void *(*function)(void *, ...);
        void *response;
} block_t;

block_t block_create(void *(*)(void *, ...), void **);
void block_destroy(block_t *);
void series_resolver(block_t *, int, int);

#endif
