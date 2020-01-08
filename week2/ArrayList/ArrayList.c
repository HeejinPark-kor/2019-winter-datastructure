#include <stdio.h>
#include "ArrayList.h"

void Init(ArrayList *plist)
{
  (plist->numOfData) = 0;
  (plist->curPosition) = -1;
}

void Insert(ArrayList *plist, Data data)
{
  if (plist->curPosition >= LIST_LEN)
  {
    puts("리스트가 가득 찼습니다\n"); // 추후 배열을 동적할당하여 배열의 크기가 가능하도록 변경
    return;
  }
  plist->arr[plist->numOfData] = data;
  (plist->numOfData)++;
}

int First(ArrayList *plist, Data *pdata)
{
  if (plist->numOfData == 0)
  {
    return False;
  }
  (plist->curPosition) = 0;
  *pdata = plist->arr[0];
  return True;
}

int Next(ArrayList *plist, Data *pdata)
{
  if (plist->curPosition >= (plist->numOfData) - 1)
  {
    return False;
  }
  (plist->curPosition)++;
  *pdata = plist->arr[plist->curPosition];
  return True;
}

Data Remove(ArrayList *plist)
{
  int rpos = plist->curPosition;
  int num = plist->numOfData;
  int i;
  Data rdata = plist->arr[rpos];

  for (i = rpos; i < num - 1; i++)
  {
    plist->arr[i] = plist->arr[i + 1];
  }

  (plist->numOfData)--;
  (plist->curPosition)--;
  return rdata;
}

int Count(ArrayList *plist)
{
  return plist->numOfData;
}