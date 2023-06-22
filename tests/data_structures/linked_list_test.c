#include "../../src/data_structures/linked_list/linked_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Create an empty linked list
  LinkedList *list = createLinkedList();

  // Insert elements into the linked list
  printf("Inserting elements to the start of the list \n");
  setFirst(list, 5);
  setFirst(list, 10);
  setFirst(list, 15);
  setLast(list, 20);
  setLast(list, 25);
  insertAfterNode(list, 2, 30);
  insertAfterNode(list, 0, 35);
  insertAfterNode(list, 10, 40);

  // Display the linked list
  printf("Linked List: ");
  displayLinkedList(list);
  printf("Linked list size is: %d \n", list->size);

  // Search for an element in the linked list
  int searchValue = 10;
  printf("Searching for node with value %d in list \n", searchValue);
  searchList(list, searchValue);

  // Delete an element from the linked list
  int deleteValue = 5;
  printf("Deleting node with value %d from list \n", deleteValue);
  removeNode(list, deleteValue);

  printf("Updated Linked List: ");
  displayLinkedList(list);

  printf("Removing first node from list \n");
  removeFirst(list);

  printf("Updated Linked List: ");
  displayLinkedList(list);

  printf("Removing last node from list \n");
  removeLast(list);

  printf("Updated Linked List: ");
  displayLinkedList(list);

  // Free the memory allocated for the linked list
  freeLinkedList(list);

  return 0;
}