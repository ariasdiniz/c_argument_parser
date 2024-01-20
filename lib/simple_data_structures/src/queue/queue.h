#ifndef ARIA_DATA_STRUCTURES_QUEUE_H
#define ARIA_DATA_STRUCTURES_QUEUE_H

struct QueueItem {
  void *value;
  struct QueueItem *next;
  struct QueueItem *prev;
};

typedef struct Queue {
  struct QueueItem *first;
  struct QueueItem *last;
  int size;
} Queue;

struct Queue *createqueue();
void *deletequeue(struct Queue *queue);
void *addtoqueue(struct Queue *queue, void *value);
void *popfromqueue(struct Queue *queue);

#endif // ARIA_DATA_STRUCTURES_QUEUE_H