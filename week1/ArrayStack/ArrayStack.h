#ifndef __A_STACK_H__
#define __A_STACK_H__

#define True 1
#define False 0
#define STACK_LEN 100

typedef int Data;

typedef struct _arrayStack
{
  Data stackArr[STACK_LEN];
  int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void Init(Stack *stack);
int IsEmpty(Stack *stack);

void Push(Stack *stack, Data data);
Data Pop(Stack *stack);
Data Peek(Stack *stack);

#endif