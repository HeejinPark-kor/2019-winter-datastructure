#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void Init(Queue *queue)
{
  queue->front = 0;
  queue->rear = 0;
}

int IsEmpty(Queue *queue)
{
  if (queue->front == queue->rear)
  {
    return True;
  }
  else
  {
    return False;
  }
}

int NextPosIdx(int pos)
{
  if (pos == QUE_LEN - 1)
  {
    return 0;
  }
  else
  {
    return pos + 1;
  }
}

void Enqueue(Queue *queue, Data data)
{
  if (NextPosIdx(queue->rear) == queue->front)
  {
    printf("Queue Memory Error!\n");
    exit(-1);
  }
  queue->rear = NextPosIdx(queue->rear);
  queue->queArr[queue->rear] = data;
}

Data Dequeue(Queue *queue)
{
  if (IsEmpty(queue))
  {
    printf("Queue Memory Error!\n");
    exit(-1);
  }
  queue->front = NextPosIdx(queue->front);
  return queue->queArr[queue->front];
}

Data Peek(Queue *queue)
{
  if (IsEmpty(queue))
  {
    printf("Queue Memory Error!\n");
    exit(-1);
  }
  return queue->queArr[NextPosIdx(queue->front)];
}