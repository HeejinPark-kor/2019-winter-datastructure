#ifndef __Tree_H__
#define __Tree_H__

typedef int Data;

typedef struct _Node
{
  Data data;
  int degree;
  Node *child;
} Node;

typedef struct _Tree
{
  Node *root;
} Tree;

Node *newNode(Data data);
Tree *newTree();
void NodeChangeData(Node *node, Data data);
void insertChild(Node *node, Data data);
void deleteAllChild(Node *node);
void deleteChild(Node *Node, Data data);

#endif