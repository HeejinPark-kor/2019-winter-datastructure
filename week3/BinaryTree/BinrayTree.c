#include <stdlib.h>
#include <stdio.h>
#include "BinaryTree.h"

Node *createNode(Data data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->data = data;
  return newNode;
}

Data getData(Node *node)
{
  return node->data;
}

void setData(Node *node, Data data)
{
  node->data = data;
}

Node *getLeftChild(Node *node)
{
  return node->left;
}

Node *getRightChild(Node *node)
{
  return node->right;
}

void setLeftChild(Node *node, Node *left)
{
  if (node->left != NULL)
  {
    free(node->left);
  }
  node->left = left;
}

void setRightChild(Node *node, Node *right)
{
  if (node->right != NULL)
  {
    free(node->right);
  }
  node->right = right;
}

void printTree(Node *root)
{
  if (root != NULL)
  {
    inOrderTraversal(root);
  }
}

void inOrderTraversal(Node *node)
{
  if (node != NULL)
  {
    inOrderTraversal(node->left);
    printf("%d\n", node->data);
    inOrderTraversal(node->right);
  }
}