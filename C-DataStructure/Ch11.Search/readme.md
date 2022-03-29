# 📌 탐색(Search)

순차탐색(Ch01)
- 정렬되지 않은 대상을 기반으로 하는 탐색

이진탐색(Ch02)
- 정렬된 대상을 기반으로 하는 탐색
> 찾는 대상의 위치와 무관하게 반씩 줄여나가면서 탐색을 진행

### 📌 보간 탐색
-   이진 탐색의 비효율성을 개선시킨 알고리즘
>   탐색 대상이 상대적으로 앞에 위치한다고 판단 되면 앞 부터 탐색 시작
>   사전에서 '사과'를 찾을때 시옷 부터 찾듯

탐색 위치(s)를 구하는 식
> 가정 : 데이터의 값과 그 데이터 저장 위치 인덱스값이 비례한다

[사진]<>


------
------
------
------
------


### 우선순위는 어떻게 결정하는가?
데이터를 근거로 우선순위를 판단할 수 있어야한다

-   그 우선순위 기준은 프로그래머가 정한다

### 우선순위 큐의 구현 방법

-   배열 기반 구현 방법❌
>   단점 : 최악의 경우 모든 데이터와 우선순위의 비교를 진행, 삽입과 삭제마다 인덱스 조정
-   연결 리스트 기반 구현 방법❌
>   단점 : 최악의 경우 모든 데이터와 우선순위의 비교를 진행
-   힙(heap) 이용 방법 ⭕️

### 📌 힙(Heap)
무엇인가를 차곡차곡 쌓아 올린 더미라는 뜻
-   이진트리이되 `완전이진트리` 이다
-   모든 노드에 `저장된 값`은 자식 노드에 저장된 값보다 `크거나 같`아야한다
>   우선순위 큐 구현을 위해 힙을 쓴다면 `값`은 `우선순위`를 말한다

최대 힙<br>
사진
-   루트 노드로 올라갈 수록 저장 값이 커지는 완전 이진 트리

최소 힙<br>
사진
-   루트 노드로 올라갈 수록 저장 값이 작아지는 완전 이진 트리

## 힙의 구현 & 우선순위 큐
힙은 우선순위 큐에 딱 어울리는 완전 이진 트리의 일종

### 힙의 데이터 저장과정

-   새로운 데이터의 최초 위치는 우선순위가 제일 낮다는 가정하에 `마지막 위치`에 저장
>   완전 이진 트리의 성질에 맞게
-   마지막 위치에 추가된 노드와 부모 노드와 우선순위 비교
-   결과에 따라 둘을 교환하고 루트 노드까지 반복

### 힙의 데이터 삭제과정
삭제는 가장 높은 우선순위의 데이터 삭제를 의미
>   삭제 후에도 힙의 구조를 유지해아한다
-   루트 노드 제거
-   마지막 노드를 루트 노드에 위치
-   자식 노드 중 우선순위가 높은 노드와 비교 후 교환

### 삽입 삭제 과정을 통한 시간복잡도
배열기반의 데이터
-   저장 : O(n)
-   삭제 : O(1)

연결 리스트 기반의 데이터
-   저장 : O(n)
-   삭제 : O(1)

힙 기반의 데이터
-   저장 : O(log n)
-   삭제 : O(log n)
힙에 저장할 수 있는 데이터 수는 트리의 높이가 하나 늘 때마다 두배씩 증가
>   데이터의 수가 `두배` 늘 때마다 비교 연산 횟수 `1회` 증가
우선순위 큐의 구현에 힙이 어울리는 이유

### 배열 기반의 힙의 구현 방법
>   연결 리스트를 기반으로 힙을 구현하면 새로운 노드를 힙의 `마지막 위치`에 추가하기 어렵다

노드에 고유의 번호를 부여
-   각 노드의 데이터가 저장될 배열의 인덱스가 된다
-   인덱스 0은 사용하지 않는다

자식과 부모 노드를 얻기위한 방법
-   왼쪽 자식 노드의 인덱스 값 : 부모 노드 인덱스 값 x 2
-   오른쪽 자식 노드의 인덱스 값 : 부모 노드 인덱스 값 x 2 + 1
-   부모 노드의 인덱스 값 : 부모 노드 인덱스 값 % 2

### 원리 이해 중심 힙 구현
우선순위 큐의 구현을 위한 힙

-   힙은 `완전 이진트리`
-   힙의 구현은 `배열 기반`이며 인덱스 0은 사용하지 않음
-   `힙에 저장된 노드 개수` == 마지막 노드의 고유번호
-   노드의 고유번호 == 노드가 저장되는 배열의 `인덱스 값`
-   우선순위를 나타내는 정수 값이 적을수록 높은 우선순위(가정)

헤더파일로 변수, 함수 선언 : [SimpleHeap.h](https://github.com/Ejaeda/C_lang/blob/master/C-DataStructure/Ch09.Priority_Queue/File/SimpleHeap.h)<br>
함수 정의 : [SimpleHeap.c](https://github.com/Ejaeda/C_lang/blob/master/C-DataStructure/Ch09.Priority_Queue/File/SimpleHeap.c)<br>
메인 함수 : [SimpleHeapMain.c](https://github.com/Ejaeda/C_lang/blob/master/C-DataStructure/Ch09.Priority_Queue/File/SimpleHeapMain.c)<br>

문제점
```.c
typedef struct _heapElem
{
    Priority pr;    //  typedef int Priority
    HData data      //  typedef char HData
}

void    HInsert(Heap *ph, HData data, Priority pr);
```
우선순위를 직접 결정해서 적어야 하는 번거로움이 발생

### 📌 이를 개선한 힙 구현
프로그래머가 우선순위의 판단 기준을 힙에 설정할 수 있어야 한다
-   이전의 구조체
```.c
    //  데이터와 우선순위를 하나로 묶기위한 구조체
    typedef struct _heapElem
    {
        Priority pr         //  typedef int Priority
        HData data;         //  typedef char HData
    } HeapElem;

    typedef struct _heap
    {
        int numOfData;
        HeapElem heapArr[HEAP_LEN];
    } Heap;
```

-   개선된 구조체 정의
```.c
    typedef struct _heap
    {
        // 두개의 데이터 우선순위의 높낮이를 판단하는 함수를 등록하기 위한 포인터 변수
        PriorityComp *comp; //  typedef int PriorityComp(HData d1, HData d2);
        int numOfData;
        HData heapArr[HEAP_LEN];    //  typedef char HData
    } Heap;
```
두개의 데이터 우선순위 높낮이를 판단하는 함수 가이드라인
-   첫 번째 인자의 우선순위가 높다면, 0보다 큰 값이 반환
-   두 번째 인자의 우선순위가 높다면, 0보다 작은 값이 반환
-   두 개의 인자의 우선순위가 같다면, 0이 반환

힙 초기화 함수 수정
```.c
    void    HeapInit(Heap *ph, PriorityComp pc)
    {
        ph->numOfData = 0;
        ph->comp = pc;  //  (추가) 우선순위 비교에 사용되는 함수의 등록
    }
```

HInsert 함수 수정
```.c
    void HInsert(Heap *ph, HData data);
```

(수정)<br>
헤더파일로 변수, 함수 선언 : [UsefulHeap.h](https://github.com/Ejaeda/C_lang/blob/master/C-DataStructure/Ch09.Priority_Queue/File/UsefulHeap.h)<br>
함수 정의 : [UsefulHeap.c](https://github.com/Ejaeda/C_lang/blob/master/C-DataStructure/Ch09.Priority_Queue/File/UsefulHeap.c)<br>
메인 함수 : [UsefulHeapMain.c](https://github.com/Ejaeda/C_lang/blob/master/C-DataStructure/Ch09.Priority_Queue/File/UsefulHeapMain.c)<br>

### 📌 완성한 힙을 이용한 우선순위 큐 구현

우선순위 큐 자료구조의 ADT
-   void    PQueueInit(PQueu *ppq, PriorityComp pc);
>   -   우선순위 큐 초기화
>   -   우선순위 큐 생성 후 제일 먼저 호출되어야 하는 함수

-   int     PQIsEmpty(PQueue *ppq);
>   -   우선순위 큐가 빈 경우 TRUE(1), 아니면 FALSE(0) 반환

-   void PEnqueue(pQueue *ppq, PQData data);
>   -   우선순위 큐에 데이터 저장, 매개변수 data로 전달된 값 저장

-   PQData PDequeue(PQueue * ppq)
>   -   우선순위가 가장 높은 데이터 삭제
>   -   삭제된 데이터는 반환
>   -   본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되야함

우선순위큐 <br>
헤더파일 선언 : [PriorityQueue.h](https://github.com/Ejaeda/C_lang/blob/master/C-DataStructure/Ch09.Priority_Queue/File/PriorityQueue.h)<br>
함수 정의 : [PriorityQueue.c](https://github.com/Ejaeda/C_lang/blob/master/C-DataStructure/Ch09.Priority_Queue/File/PriorityQueue.c)<br>
메인 함수 : [PriorityQueueMain.c](https://github.com/Ejaeda/C_lang/blob/master/C-DataStructure/Ch09.Priority_Queue/File/PriorityQueueMain.c)<br>
