#include "PriorityQueue.h"

void PQueueInit(PQueue *ppq)
{
  ppq->numOfData = 0;
}

int PQIsEmpty(PQueue *ppq)
{
  if (ppq->numOfData == 0)
  {
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

int GetParentIDX(int idx)
{
  return idx / 2;
}

int GetLChildIDX(int idx)
{
  return idx * 2;
}

int GetRChildIDX(int idx)
{
  return idx * 2 + 1;
}

int ComparePriority(PQueue *ppq, int idx)
{
  if (GetLChildIDX(idx) > ppq->numOfData)
  {
    return 0;
  }
  else if (GetLChildIDX(idx) == ppq->numOfData)
  {
    return GetLChildIDX(idx);
  }
  else
  {
    if (ppq->heapArr[GetLChildIDX(idx)].pr > ppq->heapArr[GetRChildIDX(idx)].pr)
    {
      return GetRChildIDX(idx);
    }
    else
    {
      return GetLChildIDX(idx);
    }
  }
}

void PEnqueue(PQueue *ppq, Data data, Priority pr)
{
  int idx = ppq->numOfData;
  PQElem el = {pr, data};

  while (idx != 1)
  {
    if (pr < (ppq->heapArr[GetParentIDX(idx)].pr))
    {
      ppq->heapArr[idx] = ppq->heapArr[GetParentIDX(idx)];
      idx = GetParentIDX(idx);
    }
    else
      break;
  }
  ppq->heapArr[idx] = el;
  ppq->numOfData += 1;
}

Data PDequeue(PQueue *ppq)
{
  Data returnData = (ppq->heapArr[1].data);
  PQElem lastEl = ppq->heapArr[ppq->numOfData];

  int parentIdx = 1;
  int childIdx;

  while (childIdx = ComparePriority(ppq, parentIdx))
  {
    if (lastEl.pr <= ppq->heapArr[childIdx].pr)
    {
      break;
    }
    ppq->heapArr[parentIdx] = ppq->heapArr[childIdx];
    parentIdx = childIdx;
  }
  ppq->heapArr[parentIdx] = lastEl;
  ppq->numOfData -= 1;
  return returnData;
}