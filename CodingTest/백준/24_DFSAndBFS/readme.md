# [DFS와 BFS](https://www.acmicpc.net/problem/1260) 

### :point_right: [1260](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/24_DFSAndBFS/01_1260.c)

- 핵심
```.c
1. DFS와 BFS 기본
```

- 문제접근
```.c
1. graph를 배열로 표현
2. DFS 함수
3. BFS 함수
```

- 코드 구현
1. graph를 배열로 표현
```.c
#include <stdio.h>
#define MAX_N 1001
int gragh[MAX_N][MAX_N] = {0};

int main()
{
    int N, M, V;
    int i, j;

    i = 0;
    scanf("%d %d %d", &N, &M, &V);
    while (M--)
    {
        scanf("%d %d", &i, &j);
        graph[i][j] = 1;
        graph[j][i] = 1;
    }
}
```

2. DFS
```.c
int use_DFS[MAX_N] = {0};

void    DFS(int N, int V)
{
    int idx;

    use_DFS[V] = 1;
    printf("%d", V);

    idx = 0;
    while (++idx <= N)
    {
        if (graph[V][idx] && !use_DFS[V])
            DFS(N, idx);
    }
}
```

3. BFS
```.c
int use_BFS[MAX_N] = {0};
int queue[MAX_N] = {0};

void    BFS(int N, int V)
{
    int front, rear, pop, idx;
    front = rear = 0;

    use_BFS[V] = 1;
    printf("%d", V);
    queue[rear] = V;
    rear++;
    while (front < rear)
    {
        pop = queue[front]
        front++;
        idx = 0;
        while (++idx <= N)
        {
            if (graph[pop][idx] && !use_BFS[idx])
            {
                printf("%d", idx);
                queue[rear] = idx;
                rear++;
                use_BFS = 1;
            }
        }
    }
}
```
-  새로 안 사실

💡 BFS

    -   front = 0, rear = 0, pop 사용
    -   출력한 숫자 1로 썻다 표시
    -   queue[rear] = V 넣고 rear++
    -   rear++  하더라도 front가 해당 숫자 책임
    -   gragh[방금쓴 숫자][idx++] 확인
    -   idx 출력하고 쓴 숫자 queue[rear]에 담고 rear++ 
    -   쓴 숫자 1 처리 
    -   쓴 숫자를 바로 행으로 넣으니까 BFS

💡 그래프를 배열로 표시하는 방법

    -   2차원 배열 idx, jdx를 통해 1값 넣기

💡 중복 사용하지 않는법

    -   숫자 1차원 배열을 만들고 사용했다면 1값 주기
    
💡 DFS 와 BFS

    -   DFS 는 재귀를 사용한다
    -   BFS 는 queue를 사용한다

-----

# [미로 탐색](https://www.acmicpc.net/problem/2178) 

### :point_right: [2178](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/24_DFSAndBFS/05_2178.c)

- 핵심
```.c
1. 각 정점을 최단 경로로 방문하는 BFS를 활용
```

- 문제접근
```.c
1. graph를 배열로 표현
2. BFS 함수

* 어떻게 이동 시킬 것인가?

* 각각의 수들은 붙어서 입력 -> "%1d", graph[idx][jdx]
```

- 코드 구현
1. graph를 배열로 표현
```.c
    // (1,1)부터 출발하므로 graph[1][1] 부터 입력받기

    scanf("%d %d", &N, &M);

    idx = 0
    while (++idx <= N)
    {
        jdx = 0;
        while (++jdx <= M)
        {
            printf("%1d", &graph[idx][jdx]);
        }
    }
```

2. BFS
```.c
    // 어떻게 이동 시킬 것인가?
    //          동  서  남  북
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // 1. while 문을 돌리면서 동 서 남 북으로 이동 시키기
    // 2. 만약 이동한 지점이 범위를 벗어나거나
    //    이동한 지점이 1이 아닌 경우는 그냥 넘기기
    // 3. 위 조건을 모두 충족 한다면 이동 + count++;

    // BFS는 queue를 활용
    // 1. queue에 시작 점을 담고
    // 2. 담을 때마다 rear++;
    // 3. pop에 queue[front] 주고 
    // 4. 줄 때마다front++;

    int BFS()
    {
        int front, rear, pop_x, pop_y;
        int move_x, move_y;

        front = rear = 0;
        queue[rear][0] = 1; (x = 1) // (1,1)에서 출발
        queue[rear][1] = 1; (y = 1)
        rear++;

        while (front < rear)
        {
            // 반복문마다 동 서 남 북 이동
            pop_x = queue[front][0];
            pop_y = queue[front][1];
            front++;

            idx = -1;
            while (++idx < N)
            {
                move_x = pop_x + dx[idx];
                move_y = pop_y + dy[idx];
            
                // 영역 이탈
                if (move_x < 1 || move_y < 1 
                || move_x > N || move_y > M)
                    continue;

                // 영역 내용이 1
                if (graph[move_x][move_y] != 1)
                    continue;

                // 이동한 좌표가 가능하다면 해당 영역에 +1
                // 마지막 도착점인 [N][M]의 값을 출력하면 되니까
                graph[move_x][move_y] = graph[pop_x][pop_y] + 1;
                queue[rear][0] = move_x;
                queue[rear][1] = move_y;
                rear++;
            }
        }
        return (graph[N][M]);
    }

```
-  새로 안 사실

💡 붙어서 하나씩 입력받고 싶을 때

    -   printf("%1d", &arr[][]);
>   %1d를 쓰면 입력받은 정수도 문자 단위로 나누어서 처리가 가능하다

💡 BFS

    -   front = 0, rear = 0,
>   front == rear 는 queue가 비었음을 의미
    -   queue에 시작점을 rear로 저장하고 rear++;
    -   queue에 저장값을 front로 빼고 front++; 
>   뺀 값은pop에 저장
    -   시작점에서 동 서 남 북 이동 후 가능한 영역에 +1을 해야하므로
>   dx[4] = {1, -1, 0, 0};  dy[4] = {0, 0, -1, 1}; 사용
    -   pop + dx, dy 이동 값을 move_x, move_y 변수에 저장

💡 DFS 와 BFS

    -   DFS 는 재귀를 사용한다
    -   BFS 는 queue를 사용한다

-----

# [토마토](https://www.acmicpc.net/problem/7576) 

### :point_right: [7576](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/24_DFSAndBFS/06_7576.c)

- 핵심
```.c
0. 반복문이 돌면서 시작점이 바로바로 바뀐다 -> BFS
1. 각 정점을 최단 경로로 방문하는 BFS를 활용
```

- 문제접근
```.c
1. graph를 2차원 배열로 표현
2. BFS 함수

* 어떻게 이동 시킬 것인가
```

- 코드 구현
1. graph를 배열로 표현
>   토마토가 익은 경우 -> 출발지점이므로 enqueue
>   토마토가 익지 않은 경우 -> 익어야 하는 갯수 이므로 cnt++;
```.c
    idx = -1;
    while (++idx < M)
    {
        jdx = -1;
        while (++jdx < N)
        {
            scanf("%d" &graph[idx][jdx]);
            if (!graph[idx][jdx])
                cnt++;
            else if (graph[idx][jdx] == 1)
            {
                // (x, y) 좌표 전달
                queue[rear][0] = idx;
                queue[rear][1] = jdx;
                rear++;
            }
        }
    }
```

2. BFS
```.c
    // 어떻게 이동 시킬 것인가?
    //          동  서  남  북
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // 1. while 문을 돌리면서 동 서 남 북으로 이동 시키기
    // 2. 만약 이동한 지점이 범위를 벗어나거나
    //    이동한 지점이 -1인 경우 그냥 넘기기
    // 3. 이동한 지점이 0인 경우 다음 출발점이므로 enqueue
    // 4. 위 조건을 모두 충족 한다면 이동 + count++;

    // BFS는 queue를 활용
    // 1. queue에 시작 점을 담고
    // 2. 담을 때마다 rear++;
    // 3. pop에 queue[front] 주고 
    // 4. 줄 때마다front++;

    int BFS()
    {
        int front, rear, pop_x, pop_y;
        int move_x, move_y;

        front = rear = 0;
        // main함수에서 이미 시작점이 queue에 저장된 상태

        while (front < rear)
        {
            // 반복문마다 동 서 남 북 이동
            pop_x = queue[front][0];
            pop_y = queue[front][1];
            front++;

            idx = -1;
            while (++idx < 4)
            {
                move_x = pop_x + dx[idx];
                move_y = pop_y + dy[idx];
            
                // -1은 토마토가 없는 구역이므로 0 또는 1
                if (move_x >= 0 || move_y >= 0 
                || move_x < M || move_y < N)
                {
                    if (!graph[move_x][move_y])
                    {
                        // 마지막 출력값이 되므로
                        graph[move_x][move_y] = graph[pop_x][pop_y] + 1;
                        queue[rear][0] = move_x;
                        queue[rear][1] = move_y;
                        rear++;
                        cnt--; // 0이 익어 1로 변경해줘야 하므로
                    }
                }
            }
        }
        if  (!cnt)
        // 마지막 도착 지점은 dx, dy 이동하지 않으므로
        // (pop_x, pop_y) 이다
        // -1을 해주는 이유
        // 처음 시작을 1 토마토 시작점에서 하므로 그 값을 뺀다
            return (graph[pop_x][pop_y] -1);
        
        // cnt가 0이 아니라는 것은 토마토가 모두 익지 않았다는 것
        return (-1);
    }

```
-  새로 안 사실

💡 여러 시작점에서 BFS가 시작이 되어도 결과는 똑같다

    -   main함수에서 시작점들을 queue에 담으니까 다를게 없다

💡 BFS의 출력값에 집중하자

    -   모든 토마토가 익는데 몇일이 걸리는가?
    -   먼저 익어햐는 토마토의 갯수를 cnt++;
    -   dx, dy가 조건에 맞게 통과할 경우 cnt--; 
    -   dx, dy 이동된 자리마다 시작 점의 값 + 1
>   반복문이 도는 갯수만큼 더해지므로
    
💡 DFS 와 BFS

    -   DFS 는 재귀를 사용한다
    -   BFS 는 queue를 사용한다

-----

# [3d 토마토](https://www.acmicpc.net/problem/7569) 

### :point_right: [7569](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/24_DFSAndBFS/07_7569.c)

- 핵심
```.c
0. 06 문제 + 3d
1. z축이 생겼다
```

- 문제접근
```.c
1. graph를 3차원 배열로 표현
> 어떻게 입력할 것인가
```

- 코드 구현
1. graph를 3차원 배열로 표현
>   x, z 고정한 상태로 y값을 입력받는다
>   x, y 모두 다 입력받아야 z값이 ++된다
>   반복문의 구조는 y -> x -> z
```.c
    scanf("%d %d %d", &M, &N, &H);
    z = -1;
    while (++z < H)
    {
        x = -1;
        while (++x < N)
        {
            y = -1;
            while (++y < M)
            {

                // z x y 순으로 반복하지만
                // 입력값은 x y z 순이여도 상관없음!
                // [0][y][0] 상태로 입력 받는거니까!
                scanf("%d", &graph[x][y][z]);
                if (!graph[x][y][z])
                    cnt++;
                else if(graph[x][y][z] == 1)
                {
                    queue[rear][0] = x;
                    queue[rear][1] = y;
                    queue[rear][2] = z;
                    rear++;
                }
            }
        }
    }
```

-  새로 안 사실

💡 x, y, z 축을 입력 받을때는 입력값에 따라 구성이 다르다
>   위 문제의 경우 z x y순이어야 한다

-----

# [숨바꼭질](https://www.acmicpc.net/problem/1697) 

### :point_right: [1697](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/24_DFSAndBFS/08_1697.c)

- 핵심
```.c
0. 수빈이는 걸을 수 있고(+1 ,-1) 순간이동 할 수 있다(*2)
1. N에서 시작하여 위 세가지 방법을 통해 K에 도달 해야한다
2. 상하좌우는 경우의 수가 4가지 이므로 idx = 0 ; idx < 4 ; idx++
3. 경우의 수가 3가지로 만들면 된다
4. 출력값을 어떻게 할 지 생각해야한다 

```

- 문제접근
```.c
3. 나는 걸을경우 순간이동 할 경우 따로 했는데 그럴 필요는 없다
>   if (idx == 0) wp = pop + 1;
>   else if (idx == 1) wp = pop - 1;
>   else if (idx == 2) wp = pop * 2;

4. visit[] 배열을 활용한다
>   종료 조건은 N == K or visit[pop] 이므로
> visit[MAX] = {0}로 설정하고 visit[pop]에 값을 더해준다
```

- 코드 구현
4. 출력 값 산출
>   
```.c
    while (front < rear)
    {
        pop = queue[front];
        front++;

        idx = -1;
        while (++idx < 3)
        {
            if (idx == 0) np = pop + 1;
            else if (idx == 0) np = pop - 1;
            else if (idx == 0) np = pop * 1;
            
            if (np >= 0 && np < 100001 && !visit[np])
            {
                // 이전 값을 다음 자리에 더해준다!!
                visit[np] = visit[pop] + 1;
                queue[rear] = np;
                rear++;
            }
        }
        // 어짜피 도착점은 K니까
        return (visit[K])

    }
```

-  새로 안 사실

💡 반복문의 갯수를 저장하고 출력하고 싶을 경우
>   visit[idx]로 출력을 할 수 있다

-----

# [숨바꼭질2](https://www.acmicpc.net/problem/12851) 

### :point_right: [12851](https://github.com/Ejaeda/Data_Structure/blob/master/CodingTest/%EB%B0%B1%EC%A4%80/24_DFSAndBFS/08_2_12851.c)

- 핵심
```.c
1. 도달 최단거리 뿐만 아니라 경우의 수를 구해야한다
```

- 문제접근
```.c
0. 이전 문제에서는 최단 거리만 구해야 했으므로 중복을 일체 허용하지 않았다
1. 1이 4까지 도달하기 위해
>   +1, *2 방법과
>   *2, *2 방법이 있으므로 2가지 모두 pop 되어야한다

2. 경우의 수 카운팅이 필요하다
```

- 코드 구현
1. 숨바꼭질 문제 코드는 push하는 곳에 v[np] = v[pop] +1 한다
> 따라서 중복되는 경우의 수가 !v[np]에서 걸린다
-   해결방안
> pop하는 곳에서 v[np] = v[pop] + 1 한다
> pop을 한다는 것은 이미 한 cycle이 더 돌았음을 의미한다
> 때문에 중복되는 경로지만 pop가 다르다는 것은 각자 최단 거리가 다름을 의미한다

2. 경우의 수 카운팅은 pop할때 배열로 카운팅한다
> !visit[np]하지 않지만 중복될 경우 카운팅을 해줘야한다
> cnt[np] += cnt[pop]; // cnt[np] += 1 아니다!
> BFS의 특정에 유의하자

```.c
    queue[rear] = N;
    rear++;
    cnt[N] = 1;  // 경우의 수니까 1로 출발
    check[N] = 1; // pop에서 방문 표시
    while (front < rear)
    {
        pop = queue[front];
        front++;

        idx = -1;
        while (++idx < 3)
        {
            if (idx == 0) np = pop + 1;
            else if (idx == 0) np = pop - 1;
            else if (idx == 0) np = pop * 1;
            
            if (np >= 0 && np < MAX)
            {
                if(!check[np])
                {
                    queue[rear] = np;
                    rear++;

                    check[np] = 1; // pop에서 방문 표시
                    result[np] = result[pop] + 1;

                    // count는 중복안된 경로이므로 같은 경로임
                    cnt[np] = cnt[pop]
                }           
                // 중복 경우의 수 처리
                else if(result[np] == result[pop] + 1)
                {
                    // 중복되기까지 경우의 수들은 다르므로
                    cnt[np] += cnt[pop];
                }
            }
        }
        ...

    }
```

-  새로 안 사실

💡 push에 방문 처리하는 것과 pop에 방문 처리 하는것의 차리
>   push에 방문처리 
>   -> 다음 출발지를 queue에 저장 하자마자 초기화
>   => 중복이 불가해진다

>   pop에 방문처리 
>   -> 같은 pop단계 에서는 push가 진행 되더라도 초기화 안됨
>   => 같은 pop 단계에서 얼마든지 중복이 가능

💡 방문과 최단거리가 확실하게 역활이 생기므로 하나의 배열로는 부족
>   처음에 숨바꼭질1 문제처럼 1개의 배열로 방문체크까지 하려했음
>   각각의 역할이 분명하기 때문에 2개의 배열이 필요하다

-----