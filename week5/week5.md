# 정렬 (Sort)

## 대표적인 정렬의 종류

* O(n^2)
  * 버블 정렬 (Bubble Sort)
  * 선택 정렬 (Selection Sort)
  * 삽입 정렬 (Insertion Sort)
* O(n log n)
  * 병합 정렬 (Merge Sort)
  * 힙 정렬 (Heap Sort)
  * 퀵 정렬 (Quick Sort)
* 그외
  * 기수 정렬 (Radix Sort)
  * 카운팅 정렬 (Counting Sort)

## 버블 정렬

![Bubble Sort](images/Bubble-sort.gif)

인접한 두 개의 데이터를 비교해 가면서 정렬을 진행하는 방식

```
void BubbleSort(int arr[], int n)
{
  int i, j;
  int temp;

  for(i=0; i<n-1; i++)
  {
    for(j=0; j<(n-i)-1; j++)
    {
      if(arr[j] > arr[j+1])
      {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}
```

## 선택 정렬

![Selection Sort](images/Selection-Sort.gif)

정렬 순서상 가장 앞서는 것을 **선택**하여 가장 왼쪽으로 이동시키고, 원래 그 자리에 있던 데이터는 빈 자리에 놓는 방식

```
void SelectionSort(int arr[], int n)
{
  int i, j;
  int maxIdx;
  int temp;

  for(i=0; i<n-1; i++)
  {
    maxIdx = i;

    for(j=i+1; j<n; j++)
    {
      if(arr[j] < arr[maxIdx])
      {
        maxIdx = j;
      }
    }

    temp = arr[i];
    arr[i] = arr[maxIdx];
    arr[maxIdx] = temp;
  }
}

```

## 삽입 정렬

![Insertion Sort](images/Insertion-sort.gif)

배열을 정렬된 부분과 그렇지 않은 부분으로 나누어 정렬된 부분의 다음 데이터의 위치를 찾아 삽입하는 방식

```
void InsertionSort(int arr[], int n)
{
  int i, j;
  int insData;

  for(i=1; i<n; i++)
  {
    insData = arr[i];

    for(j=i-1; j>=0; j--)
    {
      if(arr[j] > insData)
      {
        arr[j+1] = arr[j];
      }
      else
      {
        break;
      }
    }
    arr[j+1] = insData;
  }
}
```

## 병합 정렬

![Merge Sort](images/Merge-sort.gif)

## 퀵 정렬

![Quick Sort](images/Quicksort.gif)