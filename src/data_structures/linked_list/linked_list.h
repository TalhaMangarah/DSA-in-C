#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct LinkedList {
  Node* head;
  Node* tail;
  int size;
} LinkedList;

LinkedList *createLinkedList();

Node *createNode(int data);

bool searchList(LinkedList *list, int valueToFind);

void displayLinkedList(LinkedList *list);

void freeLinkedList(LinkedList *list);

void setFirst(LinkedList *list, int value);

void setLast(LinkedList *list, int value);

void insertAfterNode(LinkedList *list, int position, int data);

void removeFirst(LinkedList *list);

void removeLast(LinkedList *list);

void removeNode(LinkedList *list, int data);

bool is_list_empty(LinkedList *list);

#endif /* LINKED_LIST_H */