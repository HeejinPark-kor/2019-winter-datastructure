# Week 1 - 자료구조와 Stack, Queue, Deque

## 자료구조

### 자료구조란?

1. 데이터를 표현하고 저장하는 방법
2. C에서 사용하는 변수, 구조체 등등 모든 것이 자료구조
3. 데이터를 효율적으로 관리하기 위해 학습

### 자료구조의 분류

1. 선형구조
   - 리스트
   - 스택
   - 큐
2. 비선형구조
   - 트리
   - 그래프
3. 파일구조
   - 순차파일
   - 색인파일
   - 직접파일
4. 단순구조
   - 정수
   - 실수
   - 문자
   - 문자열

## Stack

### 개념적 정의

LIFO(Last-In, First-Out) 먼저 저장된 데이터가 나중에 나오는 구조
예시) 프링글스 통(마지막에 들어간 감자칩을 먼저 먹는다)

### 기능적 구성

1. Stack에 데이터를 저장한다 - Push
2. Stack에서 데이터를 꺼낸다 - Pop
3. Stack에 가장 마지막에 저장된 데이터를 확인한다 - Peek

### Operations

```
void Init(Stack *stack);
- 스택의 초기화를 진행한다
- 스택 생성 후 제일 먼저 호출되어야 하는 함수이다

int IsEmpty(Stack *stack);
- 스택이 비어있는 경우 1, 그렇지 않은 경우 0을 반환한다
- Boolean형을 지원할 경우 True, False로 대체 가능하다

void Push(Stack *stack, Data data);
- 스택에 데이터를 저장한다

Data Pop(Stack *stack);
- 마지막에 저장된 데이터를 삭제한다
- 삭제된 데이터는 반환한다
- 단 본 함수의 호출을 위해서는 데이터가 하나 이상 스택에 존재해야 한다

Data Peek(Stack *stack);
- 마지막에 저장된 데이터를 반환하되 삭제하지 않는다
- Pop과 마찬가지로 데이터가 하나 이상 스택에 존재해야 한다
```

### 배열 기반 Stack 구현

1. ArrayStack 구조체를 생성하여 사용한다
2. 구조체 내부에는 데이터 저장을 위한 stackArr배열과 마지막 저장된 위치를 기록하는 topIndex 변수를 정의한다
3. 가장 마지막 저장된 위치를 Stack에서는 top이라고 한다
4. 위 Operation을 구현한다

### 숙제

_Stack을 활용하여 계산기 구현_

1. 소괄호를 파악하여 그 부분을 먼저 연산한다
2. 연산자의 우선순위를 근거로 연산의 순위를 결정한다
   tip) Google에 후위표기법, 중위표기법 관련 내용을 검색해보면 쉽게 구현할 수 있다

## Queue

### 개념적 정의

FIFO(First-IN, First-Out) 먼저 들어간 데이터가 먼저 나오는 구조
예시)

### 기능적 구성

1. Queue에 데이터를 저장한다 - Enqueue
2. Queue에서 데이터를 꺼낸다 - Dequeue
3. 가장 먼저 저장된 데이터를 확인한다 - Peek

### Operations

```
void Init(Queue *queue);
- 큐의 초기화를 진행한다
- 큐 생성 후 제일 먼저 호출되어야 하는 함수이다

int IsEmpty(Queue *queue);
- 큐가 빈 경우 1, 그렇지 않은 경우 0을 반환한다

void Enqueue(Queue *queue, Data data);
- 큐에 데이터를 저장한다

Data Dequeue(Queue *queue);
- 저장순서가 가장 앞선 데이터를 삭제한다
- 삭제된 데이터는 반환한다
- 본 함수의 호출을 위해서는 데이터가 큐에 하나 이상 존재해야 한다

Data Peek(Queue *queue);
- 저장순서가 가장 앞선 데이터를 확인한다
- 단 데이터는 삭제하지 않는다
- 본 함수의 호출을 위해서는 데이터가 큐에 하나 이상 존재해야 한다
```

### 배열 기반 Queue 구현

1. 큐의 머리(Front), 와 꼬리(Rear)의 위치를 가르키는 변수를 만든다
2. 각각 변수에 해당하는 Index를 지정하여 기록한다
3. 해당 Operation을 구현한다

### 배열 기반 Queue의 단점

**배열의 끝까지 Rear가 도달한 경우 데이터를 저장하지 못한다**

### 원형 큐의 구현

1. Rear가 배열의 끝에 도달한 경우 배열의 맨 앞으로 이동한다
2. 이 때 배열의 모양이 원형과 같다 하여 원형 큐라고 한다
3. 배열이 가득 찬 상황을 대비하여 항상 데이터는 N-1개 저장할 수 있다
4. Front와 Rear가 같은 위치를 가르키고 있으면 비어있는 상태
5. Rear가 가르키는 위치의 앞을 Front가 가르키고 있으면 가득 찬 상태

### 숙제

두개의 스택으로 큐를 구현해 보세요
맨 아래 링크 참조

## Deque

### 개념적 정의

_Double-ended Queue_
양쪽 끝에서 삽입과 삭제가 모두 가능한 자료구조

### 기능적 구성

1. 앞쪽에 저장
2. 뒷쪽에 저장
3. 앞쪽에서 삭제
4. 뒷쪽에서 삭제

### Operations

```
void Init(Deque *deque);
- 덱의 초기화를 진행한다
- 덱 생성 후 제일 먼저 호출되어야 하는 함수이다

int IsEmpty(Deque *deque);
- 덱이 빈 경우 1, 그렇지 않은 경우 0을 반환한다

void AddFirst(Deque *deque, Data data);
- 덱의 머리에 데이터를 저장한다

void AddLast(Deque *deque, Data data);
- 덱의 꼬리에 데이터를 저장한다

Data RemoveFirst(Deque *deque);
- 덱의 머리에 위치한 데이터를 반환 및 제거한다

Data RemoveLast(Deque *deque);
- 덱의 꼬리에 위치한 데이터를 반환 및 제거한다

Data GetFirst(Deque *deque);
- 덱의 머리에 위치한 데이터를 반환한다

Data GetLast(Deque *deque);
- 덱의 꼬리에 위치한 데이터를 반환한다
```

## 숙제 참고 링크

[스택 계산기 구현](https://m.blog.naver.com/PostView.nhn?blogId=soohan530&logNo=221136285007&proxyReferer=https%3A%2F%2Fwww.google.com%2F)

[두 개의 Stack으로 하나의 Queue 구현](https://krgoodnews.tistory.com/entry/%EB%91%90-%EA%B0%9C%EC%9D%98-Stack%EC%9C%BC%EB%A1%9C-%ED%95%98%EB%82%98%EC%9D%98-Queue%EB%A5%BC-%EA%B5%AC%ED%98%84%ED%95%98%EB%9D%BC)
