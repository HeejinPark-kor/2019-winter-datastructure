#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

int main(int argc, const char *argv[])
{
  Node *SSL = NULL;
  Node *newNode = NULL;
  Node *searchedNode = NULL;
  newNode = CreateNode(10);
  InsertLast(&SSL, newNode);
  newNode = CreateNode(20);
  InsertLast(&SSL, newNode);
  newNode = CreateNode(30);
  InsertLast(&SSL, newNode);
  newNode = CreateNode(25);
  searchedNode = getNode(SSL, 1);
  InsertLast(searchedNode, newNode);
}