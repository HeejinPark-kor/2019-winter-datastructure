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

![time-complex](images/sort-time-complexity.png)

## 버블 정렬

![Bubble Sort](images/Bubble-sort.gif)

인접한 두 개의 데이터를 비교해 가면서 정렬을 진행하는 방식

```
void bubble_sort(int list[], int n){
  int i, j, temp;

  for(i=n-1; i>0; i--){
    // 0 ~ (i-1)까지 반복
    for(j=0; j<i; j++){
      // j번째와 j+1번째의 요소가 크기 순이 아니면 교환
      if(list[j]<list[j+1]){
        temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
      }
    }
  }
}
```

## 선택 정렬

![Selection Sort](images/Selection-Sort.gif)

정렬 순서상 가장 앞서는 것을 **선택**하여 가장 왼쪽으로 이동시키고, 원래 그 자리에 있던 데이터는 빈 자리에 놓는 방식

```
void selection_sort(int list[], int n){
  int i, j, least, temp;

  // 마지막 숫자는 자동으로 정렬되기 때문에 (숫자 개수-1) 만큼 반복한다.
  for(i=0; i<n-1; i++){
    least = i;

    // 최솟값을 탐색한다.
    for(j=i+1; j<n; j++){
      if(list[j]<list[least])
        least = j;
    }

    // 최솟값이 자기 자신이면 자료 이동을 하지 않는다.
    if(i != least){
        SWAP(list[i], list[least], temp);
    }
  }
}

```

## 삽입 정렬

![Insertion Sort](images/Insertion-sort.gif)

배열을 정렬된 부분과 그렇지 않은 부분으로 나누어 정렬된 부분의 다음 데이터의 위치를 찾아 삽입하는 방식

```
void insertion_sort(int list[], int n){
  int i, j, key;

  // 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
  for(i=1; i<n; i++){
    key = list[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

    // 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
    // j 값은 음수가 아니어야 되고
    // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
    for(j=i-1; j>=0 && list[j]>key; j--){
      list[j+1] = list[j]; // 레코드의 오른쪽으로 이동
    }

    list[j+1] = key;
  }
}
```

## 병합 정렬

![Merge Sort](images/Merge-sort.gif)

분할 정복 알고리즘의 하나 이다

### 분할 정복 (divide and conquer)

1. 문제를 작은 2개의 문제로 분리하고 각각을 해결한 다음, 결과를 모아서 원래의 문제를 해결하는 전략
2. 재귀 호출을 이용하여 구현한다

### 과정

1. 리스트의 길이가 0 또는 1이면 이미 정렬된 것으롤 본다
2. 정렬되지 않은 리스트를 절반으로 잘라 비슷한 크기의 두 부분의 리스트로 나눈다
3. 각 부분의 리스트를 재귀적으로 합병 정렬을 이용해 정렬한다
4. 두 부분의 리스트를 다시 하나의 정렬된 리스트로 합병한다

```
int sorted[MAX_SIZE] // 추가적인 공간이 필요

void merge(int list[], int left, int mid, int right){
  int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;

  /* 분할 정렬된 list의 합병 */
  while(i<=mid && j<=right){
    if(list[i]<=list[j])
      sorted[k++] = list[i++];
    else
      sorted[k++] = list[j++];
  }

  // 남아 있는 값들을 일괄 복사
  if(i>mid){
    for(l=j; l<=right; l++)
      sorted[k++] = list[l];
  }
  // 남아 있는 값들을 일괄 복사
  else{
    for(l=i; l<=mid; l++)
      sorted[k++] = list[l];
  }

  // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
  for(l=left; l<=right; l++){
    list[l] = sorted[l];
  }
}

// 합병 정렬
void merge_sort(int list[], int left, int right){
  int mid;

  if(left<right){
    mid = (left+right)/2 // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
    merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
    merge_sort(list, mid+1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
    merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
  }
}
```

## 퀵 정렬

![Quick Sort](images/Quicksort.gif)

분할 정복 알고리즘중 하나이며 합병 정렬과 달리 리스트를 비균등하게 분할한다

### 과정

1. 리스트 안에 있는 한 요소를 선택한다. 이 요소를 피벗(pivot) 이라고 한다
2. 피벗을 기준으로 피벗보다 작은 요소들은 모두 왼쪽으로 옮겨지고, 피벗보다 큰 요소들은 모두 피벗의 오른쪽으로 옮겨진다
3. 피벗을 제외한 왼쪽 리스트와 오른쪽 리스트를 다시 정렬한다
4. 부분 리스트들이 더이상 분할이 불가능 할 때까지 정렬을 반복한다

```
# define MAX_SIZE 9
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

// 1. 피벗을 기준으로 2개의 부분 리스트로 나눈다.
// 2. 피벗보다 작은 값은 모두 왼쪽 부분 리스트로, 큰 값은 오른쪽 부분 리스트로 옮긴다.
/* 2개의 비균등 배열 list[left...pivot-1]와 list[pivot+1...right]의 합병 과정 */
/* (실제로 숫자들이 정렬되는 과정) */
int partition(int list[], int left, int right){
  int pivot, temp;
  int low, high;

  low = left;
  high = right + 1;
  pivot = list[left]; // 정렬할 리스트의 가장 왼쪽 데이터를 피벗으로 선택(임의의 값을 피벗으로 선택)

  /* low와 high가 교차할 때까지 반복(low<high) */
  do{
    /* list[low]가 피벗보다 작으면 계속 low를 증가 */
    do {
      low++; // low는 left+1 에서 시작
    } while (low<=right && list[low]<pivot);

    /* list[high]가 피벗보다 크면 계속 high를 감소 */
    do {
      high--; //high는 right 에서 시작
    } while (high>=left && list[high]>pivot);

    // 만약 low와 high가 교차하지 않았으면 list[low]를 list[high] 교환
    if(low<high){
      SWAP(list[low], list[high], temp);
    }
  } while (low<high);

  // low와 high가 교차했으면 반복문을 빠져나와 list[left]와 list[high]를 교환
  SWAP(list[left], list[high], temp);

  // 피벗의 위치인 high를 반환
  return high;
}

// 퀵 정렬
void quick_sort(int list[], int left, int right){

  /* 정렬할 범위가 2개 이상의 데이터이면(리스트의 크기가 0이나 1이 아니면) */
  if(left<right){
    // partition 함수를 호출하여 피벗을 기준으로 리스트를 비균등 분할 -분할(Divide)
    int q = partition(list, left, right); // q: 피벗의 위치

    // 피벗은 제외한 2개의 부분 리스트를 대상으로 순환 호출
    quick_sort(list, left, q-1); // (left ~ 피벗 바로 앞) 앞쪽 부분 리스트 정렬 -정복(Conquer)
    quick_sort(list, q+1, right); // (피벗 바로 뒤 ~ right) 뒤쪽 부분 리스트 정렬 -정복(Conquer)
  }

}
```

## 참고 사이트

[기수 정렬](https://www.zerocho.com/category/Algorithm/post/58007c338475ed00152d6c4c)

[카운팅 정렬, 기수 정렬](https://ratsgo.github.io/data%20structure&algorithm/2017/10/16/countingsort/)

[15 Sorting Algorithm (소리 주의)](https://youtu.be/kPRA0W1kECg)

