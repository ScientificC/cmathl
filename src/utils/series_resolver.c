#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <pthread.h>
#include <cml.h>

#ifdef CML_SERIES_RESOLVER
static pthread_mutex_t lock;

block_t
block_create(double *(*function)(int *, double **), double **argv)
{
        double r = 0.0;

        block_t block = {
                .function = function,
                .argv = argv,
                .from = 0,
                .delta = 0,
                .response = &r
        };

        return block;
}

void
block_destroy(block_t *block)
{
        free(block);
}

void *
process(void * arg)
{
        int i, to;
        double r;
        block_t *block;
        double *(*f)(int *, double **);
        double *f_r;

        r = 0.0;
        block = (block_t *) arg;
        f = block->function;
        to = block->from + block->delta;
        for (i = block->from; i < to; i++) {
                f_r = f(&i, block->argv);
                r = r + *f_r;
        }

        pthread_mutex_lock(&lock);
        f_r = block->response;
        *f_r += r;
        block->response = f_r;
        pthread_mutex_unlock(&lock);

        return NULL;
}

void
series_resolver(block_t *block, int max_loops, int max_threads)
{
        int i, top, t;

        top = max_loops == 0 ? MAXLOOPS : max_loops;
        t = max_threads == 0 ? MAXTHREADS : max_threads;

        pthread_t tid[top/t];
        pthread_mutex_init(&lock, NULL);

        block->delta = (int) top/t;
        for (i = 0; i < t; i++) {
                block->from = (top/t)*i;
                pthread_create(&(tid[i]), NULL, &process, block);
        }

        for (i = 0; i < t; i++) {
                pthread_join(tid[i], NULL);
        }

        pthread_mutex_destroy(&lock);
}
#endif
