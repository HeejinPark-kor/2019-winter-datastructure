#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char Data;
typedef int Priority;

typedef struct _pqEle
{
  Priority pr;
  Data data;
} PQElem;

typedef struct _PQueue
{
  int numOfData;
  PQElem heapArr[HEAP_LEN];
} PQueue;

void PQueueInit(PQueue *ppq);
int PQIsEmpty(PQueue *ppq);
void PEnqueue(PQueue *ppq, Data data, Priority pr);
Data PDequeue(PQueue *ppq);

#endif