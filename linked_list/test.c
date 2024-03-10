#include "linked_list.h"
#include <stdio.h>

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
