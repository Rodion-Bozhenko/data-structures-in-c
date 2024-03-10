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

void list_insert_at(ListNode **head, size_t index, void *data) {
  ListNode* new_node = list_new(data);

  if (index == 0 || *head == NULL) {
    new_node->next = *head;
    *head = new_node;
    return;
  }

  size_t i = 0;
  ListNode* current = *head;
  while (i < index - 1 && current != NULL) {
    current = current->next;
    i++;
  }

  if (current == NULL) {
    free(new_node);
    return;
  }

  new_node->next = current->next;
  current->next = new_node;
}

ListNode *list_find_by_at(ListNode *head, size_t index) {
  ListNode *current = head;
  size_t i = 0;
  while (i != index && current != NULL) {
    current = current->next;
    i++;
  }

  return current;
}


ListNode *list_find(ListNode *head, MatchCallback match) {
  ListNode *current = head;
  while (current != NULL) {
    if (match(current->data)) {
      return current;
    }
    current =  current->next;
  }

  return NULL;
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

void linked_list_test() {
  ListNode *head = NULL; // Start with an empty list

  // Test list_new and list_push_back
  printf("Adding elements 1, 2, 3 to the back of the list.\n");
  list_push_back(&head, (void *)1);
  list_push_back(&head, (void *)2);
  list_push_back(&head, (void *)3);
  ListNode *cur = head;
  while (cur != NULL) {
    printf("LIST %zu\n", (size_t)cur->data);
    cur = cur->next;
  }

  // Test list_len
  printf("List length after additions: %zu\n", list_len(&head));

  // Test list_push_front
  printf("Adding element 0 to the front of the list.\n");
  list_push_front(&head, (void *)0);

  // Display the list
  ListNode *current = head;
  printf("Current List: ");
  while (current != NULL) {
    printf("%zu ", (size_t)current->data); // Cast to int for demonstration
    current = current->next;
  }
  printf("\n");

  // Test list_pop_front
  printf("Popping from the front: %zu\n", (size_t)list_pop_front(&head));

  // Test list_pop_back
  printf("Popping from the back: %zu\n", (size_t)list_pop_back(&head));

  // Display the list again
  current = head;
  printf("List after pops: ");
  while (current != NULL) {
    printf("%zu ", (size_t)current->data); // Cast to int
    current = current->next;
  }
  printf("\n");

  // Test list_remove_at
  printf("Removing element at position 1.\n");
  list_remove_at(&head, 1);

  // Display the list after removal
  current = head;
  printf("List after removal: ");
  while (current != NULL) {
    printf("%zu ", (size_t)current->data); // Cast to int
    current = current->next;
  }
  printf("\n");

  printf("List length after removals: %zu\n", list_len(&head));

  while (head != NULL) {
    list_pop_front(&head);
  }
}
