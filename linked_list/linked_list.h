#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdbool.h>

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

void list_insert_at(ListNode **head, size_t index, void* data);

ListNode *list_find_by_at(ListNode *head, size_t index);

typedef bool (*MatchCallback)(void* data);

ListNode *list_find(ListNode *head, MatchCallback match);

size_t list_len(ListNode **head);

#endif
