/* Copyright (C) 2017 CMATHL

   This file is part of CML.

   CML is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   CML is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with CML. If not, see <http://www.gnu.org/licenses/>.     */

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <pthread.h>
#include "../../includes/bin/cml_threads.h"

static pthread_mutex_t lock;
double r;

block_t block_create(void *(*function)(void *,...), void **argv)
{
        block_t block;
        block.function = function;
        block.argv = argv;
        block.from = 0;
        block.delta = 0;
        return block;
}

void block_destroy(block_t *block)
{
        free(block);
}

void *process(void * arg)
{
        int i, to;
        double r;
        block_t *block;
        void *(*f)(void *, ...);
        double *f_r;

        r = 0.0;
        block = (block_t *) arg;
        f = block->function;
        to = block->from + block->delta;
        for (i = block->from; i < to; i++) {
                f_r = f(block->argv, i);
                r = r + *f_r;
        }

        pthread_mutex_lock(&lock);
        f_r = block->response;
        *f_r = r;
        block->response = f_r;
        pthread_mutex_unlock(&lock);

        return NULL;
}

void series_resolver(block_t *block, int max_loops, int max_threads)
{
        int i, top, t;

        r = 0.0;
        top = max_loops == 0 ? MAXLOOPS : max_loops;
        t = max_threads == 0 ? MAXTHREADS : max_threads;

        pthread_t tid[top/t];
        pthread_mutex_init(&lock, NULL);

        block->delta = top/t;
        for (i = 0; i < t; i++) {
              block->from = (top/t)*i;
              pthread_create(&(tid[i]), NULL, &process, block);
        }

        for (i = 0; i < t; i++) {
              pthread_join(tid[i], NULL);
        }

        pthread_mutex_destroy(&lock);
}
