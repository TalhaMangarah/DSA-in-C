#include "linked_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Node *createNode(int data)
{
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL)
  {
    return NULL;
  }
  node->data = data;
  node->next = NULL;
  return node;
}

LinkedList* createLinkedList()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) 
    {
    return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void displayLinkedList(LinkedList *list)
{
    if (list->head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    Node *tempNode = list->head;
    while(tempNode != NULL)
    {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

void freeLinkedList(LinkedList *list)
{
    if (is_list_empty(list))
    {
        free(list->head);
        free(list->tail);
        free(list);
        printf("Freed list memory");
        return;
    }

    Node *current = list->head;
    while (current != NULL)
    {
        Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(current);
    free(list);
}

bool searchList(LinkedList *list, int valueToFind)
{
    if (list->head == NULL) 
    {
        printf("Linked List is empty.\n");
        return false;
    }

    Node *tempNode = list->head;
    while (tempNode != NULL)
    {
        if (tempNode->data == valueToFind)
        {
            printf("Node with value %d found in list.\n", valueToFind);
            return true;
        }
        else 
        {
            tempNode = tempNode->next;
        }
    }
    printf("Could not find value '%d' in list", valueToFind);
    return false;
}

void setFirst(LinkedList *list, int value)
{
    Node *newNode = createNode(value);
    if (newNode == NULL)
    {
        return;
    }

    if (is_list_empty(list))
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        newNode->next = list->head;
        list->head = newNode;
    }
    
    list->size++;
}

void setLast(LinkedList *list, int value)
{
    Node *newNode = createNode(value);
    if (newNode == NULL)
    {
        return;
    }

    if (is_list_empty(list))
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size++;
}

void insertAfterNode(LinkedList *list, int position, int data)
{
    if (is_list_empty(list) && position > 0)
    {
        printf("List is empty so cannot insert after a node position > 0\n");
        return;
    }

    if (position > list->size)
    {
        printf("Position is greater than list size therefore cannot insert \n");
        return;
    }

    Node *newNode = createNode(data);
    if (newNode == NULL)
    {
        return;
    }

    Node *current = list->head;
    while (current != NULL && position != 0)
    {
        current = current->next;
        position--;
    }

    if (current == list->head) 
    {
        setFirst(list, data);
        return;
    } 
    else if (current == list->tail) 
    {
        setLast(list, data);
        return;
    } 
    else 
    {
        newNode->next = current->next;
        current->next = newNode;
        list->size++;
        return;
    }
}

void removeFirst(LinkedList *list)
{
    if(list->head == NULL)
    {
        return;
    }

    if (list->head == list->tail)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        Node *tempNode = list->head;
        list->head = list->head->next;
        free(tempNode);
    }

    list->size--;
}

void removeLast(LinkedList *list)
{
    if (is_list_empty(list))
    {
        return;
    }
    if (list->head == list->tail)
    {
        removeFirst(list);
    }

    Node *tempCurrentNode = list->head;
    Node *tempPreviousNode = NULL;
    while (tempCurrentNode != list->tail){
        tempPreviousNode = tempCurrentNode;
        tempCurrentNode = tempCurrentNode->next;
    }
    tempPreviousNode->next = NULL;
    list->tail = tempPreviousNode;
    list->size--;
    free(tempCurrentNode);
}

void removeNode(LinkedList *list, int data)
{
    if (is_list_empty(list))
    {
        return;
    }

    if (list->head == list->tail)
    {
        if (data == list->head->data)
        {
            removeFirst(list);
        } 
        else if (data != list->head->data)
        {
            return;
        }
    }

    Node *tempCurrentNode = list->head;
    Node *tempPreviousNode = NULL;
    while (tempCurrentNode != NULL)
    {
        if (tempCurrentNode->data == data)
        {
            if (tempCurrentNode == list->head)
            {
                removeFirst(list);
                return;
            }
            else if (tempCurrentNode == list->tail)
            {
                removeLast(list);
                return;
            }
            else {
            tempPreviousNode->next = tempCurrentNode->next;
            list->size--;
            free(tempCurrentNode);
            return;
            }
        }
        else {
        tempPreviousNode = tempCurrentNode;
        tempCurrentNode = tempCurrentNode->next;
        }
    }

    printf("Could not remove the node as data could not be found in list");
}

bool is_list_empty(LinkedList *list)
{
    if (list->head == NULL && list->tail == NULL)
    {
        return true;
    } 
    else {
        return false;
    }
}