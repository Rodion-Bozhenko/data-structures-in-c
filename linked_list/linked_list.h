#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct ListNode {
  void *data;
  struct ListNode *next;
} ListNode;

ListNode *list_new(void *data);
void list_push_front(ListNode **head, void *data);
void list_push_back(ListNode **head, void *data);
void *list_pop_front(ListNode **head);
void *list_pop_back(ListNode **head);
void list_remove_at(ListNode **head, size_t index);
size_t list_len(ListNode **head);

#endif
