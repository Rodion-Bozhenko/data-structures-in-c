#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  void* items;
  size_t elem_size;
  int size;
  int cap;
} Stack;

Stack stack_new(int cap, size_t elem_size);
void stack_push(Stack *s, const void* elem);
int stack_pop(Stack *s, void* elem);
int stack_peek(Stack *s, void* elem);
bool stack_empty(Stack *s);
void stack_test();

#endif
