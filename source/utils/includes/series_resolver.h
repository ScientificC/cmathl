#ifndef CML_THREADS_H
#define CML_THREADS_H

#define MAXLOOPS 100000
#define MAXTHREADS 10

typedef struct _block {
        int from;
        int delta;
        double **argv;
        double *(*function)(int *, double **);
        double *response;
} block_t;

block_t block_create(double *(*)(int *, double **), double **);
void block_destroy(block_t *);
void series_resolver(block_t *, int, int);

#endif
