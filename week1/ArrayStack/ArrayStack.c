#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

void Init(Stack *stack)
{
  stack->topIndex = -1; //아무것도 저장되어있지 않은 상태
}

int IsEmpty(Stack *stack)
{
  if (stack->topIndex == -1)
  {
    return True;
  }
  else
  {
    return False;
  }
}

void Push(Stack *stack, Data data)
{
  stack->topIndex += 1;
  stack->stackArr[stack->topIndex] = data;
}

Data Pop(Stack *stack)
{
  int rIdx;

  if (IsEmpty(stack))
  {
    printf("Stack Memory Error\n");
    exit(-1);
  }

  rIdx = stack->topIndex;
  stack->topIndex -= 1;

  return stack->stackArr[rIdx];
}

Data Peek(Stack *stack)
{
  if (IsEmpty(stack))
  {
    printf("Stack Memory Error\n");
    exit(-1);
  }

  return stack->stackArr[stack->topIndex];
}