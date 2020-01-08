#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef int Data;

typedef struct _Node
{
  Data data;
  Node *NextNode;
} Node;

Node *CreateNode(Data data);
void DeleteNode(Node *node);
void InsertLast(Node **head, Node *newNode);
Node *getNode(Node *head, int index);
void RemoveNode(Node **head, Node *removeNode);
void InsertAfter(Node *current, Node *newNode);

#endif