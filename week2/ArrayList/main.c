#include <stdio.h>
#include "ArrayList.h"

int main()
{
  ArrayList list;
  int data;
  Init(&list);

  Insert(&list, 1);
  Insert(&list, 2);
  Insert(&list, 3);
  Insert(&list, 4);
  Insert(&list, 5);

  if (First(&list, &data))
  {
    printf("%d\n", data);

    while (Next(&list, &data))
    {
      printf("%d\n", data);
    }
  }

  if (First(&list, &data))
  {
    if (data == 2)
    {
      Remove(% list);
    }
    while (Next(&list, &data))
    {
      if (data == 2)
      {
        Remove(&list);
      }
    }
  }

  if (First(&list, &data))
  {
    printf("%d\n", data);

    while (Next(&list, &data))
    {
      printf("%d\n", data);
    }
  }

  return 0;
}