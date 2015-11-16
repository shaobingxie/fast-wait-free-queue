#ifndef QUEUE_H
#define QUEUE_H

#ifdef WFQUEUE
#include "wfqueue.h"

#elif LCRQ
#include "lcrq.h"

#elif CCQUEUE
#include "ccqueue.h"

#elif MSQUEUE
#include "msqueue.h"

#elif FAAQ
#include "align.h"
#define EMPTY ((void *) 0)

typedef struct {
  volatile long P DOUBLE_CACHE_ALIGNED;
  volatile long C DOUBLE_CACHE_ALIGNED;
} queue_t DOUBLE_CACHE_ALIGNED;

typedef int handle_t;

#else
#error "Please specify a queue implementation."

#endif

void queue_init(queue_t * q, int nprocs);
void queue_register(queue_t * q, handle_t * th, int id);
void enqueue(queue_t * q, handle_t * th, void * v);
void * dequeue(queue_t * q, handle_t * th);

#endif /* end of include guard: QUEUE_H */
