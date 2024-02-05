#include "linked_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

ListNode *list_new(void *data) {
  ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
  if (new_node == NULL) {
    fprintf(stderr, "Linked List allocation error\n");
    exit(1);
  }

  new_node->data = data;
  new_node->next = NULL;

  return new_node;
}

void list_push_back(ListNode **head, void *data) {
  ListNode *new_node = list_new(data);

  if (*head == NULL) {
    *head = new_node;
    printf("PUSH_BACK %zu \n", (size_t)(*head)->data);
    return;
  }

  ListNode *current = *head;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;
  printf("PUSH_BACK %zu \n", (size_t)current->next->data);
}

void list_push_front(ListNode **head, void *data) {
  ListNode *new_node = list_new(data);
  new_node->next = *head;
  *head = new_node;
}

void *list_pop_back(ListNode **head) {
  if (*head == NULL) {
    return NULL;
  }

  bool onlyOneNode = (*head)->next == NULL;
  if (onlyOneNode) {
    void *data = (*head)->data;
    free(*head);
    *head = NULL;
    return data;
  }

  ListNode *current = *head;

  while (current->next->next != NULL) {
    current = current->next;
  }

  ListNode *last_node = current->next;
  void *data = last_node->data;

  free(last_node);
  current->next = NULL;

  return data;
}

void *list_pop_front(ListNode **head) {
  if (*head == NULL) {
    return NULL;
  }

  ListNode *first = *head;
  void *data = first->data;

  *head = first->next;
  free(first);

  return data;
}

void list_remove_at(ListNode **head, size_t index) {
  if (*head == NULL || list_len(head) <= index)
    return;

  ListNode *current = *head;

  if (index == 0) {
    *head = current->next;
    free(current);
    return;
  }

  size_t i = 0;
  while (i < index - 1 && current->next != NULL) {
    current = current->next;
    i++;
  }

  ListNode *next = current->next->next;

  free(current->next);

  current->next = next;
}

size_t list_len(ListNode **head) {
  size_t len = 0;

  ListNode *current = *head;

  while (current != NULL) {
    len++;
    current = current->next;
  }

  return len;
}
