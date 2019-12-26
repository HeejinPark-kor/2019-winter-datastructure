#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define True 1
#define False 0

#define QUE_LEN
typedef int Data;

typedef struct _CQueue
{
  int front;
  int rear;
  Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void Init(Queue *queue);
int IsEmpty(Queue *queue);

void Enqueue(Queue *queue, Data data);
Data Dequeue(Queue *queue);
Data Peek(Queue *queue);

#endif