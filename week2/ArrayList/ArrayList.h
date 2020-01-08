#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define True 1
#define False 0

#define LIST_LEN 100
typedef int Data;

typedef struct __ArrayList
{
  Data arr[LIST_LEN];
  int numOfData;
  int curPosition;
} ArrayList;

void Init(ArrayList *plist);
void Insert(ArrayList *plist, Data data);

int First(ArrayList *plist, Data *pdata);
int Next(ArrayList *plist, Data *pdata);

Data Remove(ArrayList *plist);
int Count(ArrayList *plist);

#endif