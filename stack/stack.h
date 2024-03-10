#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct {
  void* items;
  size_t elem_size;
  int size;
  int cap;
} Stack;

Stack stack_new(int cap, size_t elem_size);
void stack_push(Stack *s, const void* elem);
int stack_pop(Stack *s, void* elem);
void stack_test();

#endif
