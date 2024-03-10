#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack stack_new(int cap, size_t elem_size) {
  Stack s;
  s.cap = cap;
  s.size = 0;
  s.elem_size = elem_size;
  s.items = malloc(elem_size * cap);

  if (s.items == NULL) {
    fprintf(stderr, "Stack allocation error\n");
    exit(1);
  }

  return s;
}

void stack_push(Stack *s, const void* elem) {
  if (s->size >= s->cap) {
    s->cap *= 2;
    s->items = realloc(s->items, s->elem_size * s->cap);
    if (s->items == NULL) {
      fprintf(stderr, "Stack reallocation error\n");
      exit(1);
    }
  }

  void *target = (char*)s->items + (s->size * s->elem_size);
  memcpy(target, elem, s->elem_size);
  s->size++;
}

int stack_pop(Stack *s, void* elem) {
  if (s->size == 0) {
    return -1;
  }

  void *source = (char*)s->items + ((s->size - 1) * s->elem_size);

  if (elem != NULL) {
    memcpy(elem, source, s->elem_size);
  }

  s->size--;

  return 0;
}

void stack_test() {
  typedef struct {
    int foo;
    char* bar;
  } Foo;

  Stack stack = stack_new(2, sizeof(Foo));
  Foo value = {2, "some"};
  Foo value2 = {20000, "asdfasdfasdf"};
  stack_push(&stack, &value);
  printf("STACK CAP %d\n", stack.cap);
  stack_push(&stack, &value2);
  stack_push(&stack, &value);
  printf("STACK CAP %d\n", stack.cap);
  stack_push(&stack, &value);
  stack_push(&stack, &value2);
  printf("STACK CAP %d\n", stack.cap);
  for (size_t i = 0; i < stack.size; i++) {
    printf("STACK %zu %d %s\n", i, ((Foo*)stack.items + i)->foo, ((Foo *)stack.items + i)->bar);
  }
  Foo popped;
  stack_pop(&stack, &popped);
  stack_pop(&stack, NULL);
  printf("POPPED %d %s\n", popped.foo, popped.bar);
  for (size_t i = 0; i < stack.size; i++) {
    printf("STACK %zu %d %s\n", i, ((Foo*)stack.items + i)->foo, ((Foo *)stack.items + i)->bar);
  }
}
