#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

Node *CreateNode(Data data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->NextNode = NULL;
  return newNode;
}

void DeleteNode(Node *node)
{
  free(node);
}

void InsertLast(Node **head, Node *newNode)
{
  if (*head == NULL)
  {
    *head = newNode;
  }
  else
  {
    Node *tail = *head;
    while (tail->NextNode != NULL)
    {
      tail = tail->NextNode;
    }
    tail->NextNode = newNode;
  }
}

Node *getNode(Node *head, int index)
{
  Node *current = head;
  while (current != NULL && --index >= 0)
  {
    current = current->NextNode;
  }
  return current;
}

void RemoveNode(Node **head, Node *removeNode)
{
  if (*head == removeNode)
  {
    *head = removeNode->NextNode;
  }
  else
  {
    Node *current = *head;
    while (current != NULL && current->NextNode != removeNode)
    {
      current = current->NextNode;
    }
    if (current != NULL)
    {
      current->NextNode = removeNode->NextNode;
    }
  }
}

void InsertAfter(Node *current, Node *newNode)
{
  newNode->NextNode = current->NextNode;
  current->NextNode = newNode;
}