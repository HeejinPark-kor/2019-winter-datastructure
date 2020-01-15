#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

Node *newNode(Data data)
{
  Node *returnNode = (Node *)malloc(sizeof(Node));
  returnNode->data = data;
  returnNode->degree = 0;
  returnNode->child = NULL;
  return returnNode;
}

Tree *newTree()
{
  Tree *returnTree = (Tree *)malloc(sizeof(Tree));
  returnTree->root = NULL;
  return returnTree;
}

void NodeChangeData(Node *node, Data data)
{
  node->data = data;
}

void insertChild(Node *node, Data data)
{
  node->child = (Node *)realloc(node->child, sizeof(Node) * (node->degree + 1));
  node->child[node->degree].data = data;
  node->child[node->degree].degree = 0;
  node->child[node->degree].child = NULL;
  node->degree++;
}

void deleteAllChild(Node *node)
{
  int i;

  if (node == NULL)
  {
    return;
  }

  for (i = 0; i < node->degree; i++)
  {
    deleteAllChild(&(node->child)[i]);
  }
  free(node->child);
  node->degree = 0;
  node->child = NULL;
}

void deleteChild(Node *node, Data data)
{
  int i, j;

  for (i = 0; i < node->degree; i++)
  {
    if (node->child[i].data == data)
    {
      break;
    }
  }
  if (i == node->degree)
  {
    printf("찾는 데이터가 없습니다.\n");
    return;
  }
  deleteAllChild(&(node->child)[i]);
  for (j = i; j < node->degree - 1; j++)
  {
    node->child[j].child = node->child[j + 1].child;
    node->child[j].data = node->child[j + 1].data;
    node->child[j].degree = node->child[j + 1].degree;
  }
  node->child = (Node *)realloc(node->child, sizeof(Node) * (node->degree - 1));
  node->degree--;
}
