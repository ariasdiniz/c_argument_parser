#include "queue.h"
#include <stdlib.h>

/*
  Create a new Queue.

  @return Return a pointer to the newly created Queue.
  Return NULL in case of failure on memory allocation.
  Don't forget to free memory after usage with deletequeue(queue).
*/
struct Queue *createqueue() {
  struct Queue *queue = malloc(sizeof(struct Queue));
  if (queue == NULL) {
    return NULL;
  }
  queue->first = NULL;
  queue->last = NULL;
  queue->size = 0;
  return queue;
}

/*
  Safely delete the queue freeing the memory.
  If you used this structure to store in the values pointers for
  other manually allocated memory adresses, please free all pointers
  before calling this method.
  @param queue A pointer to a Queue.
  @return Return 0 when successful. return (void *)-1 if queue is empty or NULL.
*/
void *deletequeue(struct Queue *queue) {
  if (queue == NULL) {
    return (void *)-1;
  }
  if (queue->size == 0) {
    free(queue);
    return 0;
  }
  struct QueueItem *next;
  struct QueueItem *actual = queue->last;
  for (int i=0; i < queue->size; i++) {
    next = actual->next;
    free(actual);
    actual = next;
  }
  free(queue);
  return 0;
}

/*
  Add a new element to the queue.
  @param queue A pointer to a Queue.
  @param value A pointer to a value to be stored.
  @return Return 0 if successful. return (void *)-1 if queue is NULL or empty,
  or in case of error in memory allocation.
*/
void *addtoqueue(struct Queue *queue, void *value) {
  if (queue == NULL) {
    return (void *)-1;
  }
  struct QueueItem *item = malloc(sizeof(struct QueueItem));
  if (item == NULL) {
    return (void *)-1;
  }
  item->value = value;
  item->prev = NULL;
  if (queue->size == 0) {
    item->next = NULL;
    queue->first = item;
    queue->last = item;
    queue->size++;
    return 0;
  }
  item->next = queue->last;
  queue->last->prev = item;
  queue->last = item;
  queue->size++;
  return 0;
}

/*
  Removes the first element of the queue and return a pointer to it's value.
  Don't forget to free this pointer afterward, if it point to a manually
  allocated memory address.
  @param queue A pointer to a queue.
  @return A pointer to the value stored. return (void *)-1 if the queue is empty.
*/
void *popfromqueue(struct Queue *queue) {
  if (queue == NULL) {
    return NULL;
  }
  struct QueueItem *item = queue->first;
  void *value = item->value;
  if (item == queue->last) {
    queue->first = NULL;
    queue->last = NULL;
    queue->size--;
    free(item);
    return value;
  }
  queue->first = item->prev;
  queue->size--;
  free(item);
  return value;
}
