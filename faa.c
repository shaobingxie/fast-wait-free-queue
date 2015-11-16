#include "queue.h"
#include "primitives.h"

void queue_init(queue_t * q, int nprocs) {}
void queue_register(queue_t * q, handle_t * hd, int id)
{
  *hd = id;
}

void enqueue(queue_t * q, handle_t * th, void * val)
{
  FAA(&q->P, 1);
}

void * dequeue(queue_t * q, handle_t * th)
{
  FAA(&q->C, 1);
  return (void *) (long) *th;
}

