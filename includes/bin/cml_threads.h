#ifndef CML_THREADS_H
#define CML_THREADS_H

typedef struct _block {
        void **argv;
        void *(*function)(void *, ...);
} block_t;

#endif
