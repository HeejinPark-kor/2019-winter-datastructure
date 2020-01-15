#ifndef __BINARY_TREE__
#define __BINARY_TREE__

typedef int Data;

typedef struct _Node
{
  Data data;
  Node *left;
  Node *right;
} Node;

Node *createNode(Data data);
Data getData(Node *node);
void setData(Node *node, Data data);
Node *getLeftChild(Node *node);
Node *getRightChild(Node *node);
void setLeftChild(Node *node, Node *left);
void setRightChild(Node *node, Node *right);
void printTree(Node *root);
void inOrderTraversal(Node *node);

#endif