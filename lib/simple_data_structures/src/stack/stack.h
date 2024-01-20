#ifndef ARIA_DATA_STRUCTURES_STACK_H
#define ARIA_DATA_STRUCTURES_STACK_H

struct StackItem {
  void *value;
  struct StackItem *next;
};

/*
  The Stack data structure.
*/
typedef struct Stack {
  struct StackItem *top;
  int size;
} Stack;

struct Stack *createstack();
void *deletestack(struct Stack *stack);
void *addtostack(struct Stack *stack, void *value);
void *popfromstack(struct Stack *stack);

#endif // ARIA_DATA_STRUCTURES_STACK_H