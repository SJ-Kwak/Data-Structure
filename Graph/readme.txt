#2076016_곽서진
[Decrease_Increase_Key.c]
Min-heap에서 decrease-key와 increase-key 함수를 정의하는 프로그램

1) typedef struct element
-int key

2) typedef struct HeapType
-element heap[MAX_ELEMENT]
-int heap_size

3) void init(HeapType* h)
: heap을 초기화하는 함수
-parameter
	HeapType* h: 초기화할 heap

4) void insert_min_heap(HeapType* h, element item)
: min_heap에 item을 삽입하는 함수
-parameter
	HeapType* h: 삽입할 heap
	element item: 삽입하는 node

5) void decrease_key_min_heap(HeapType *h, int i, int key)
: heap의 node 안의 값보다 작은 값을 대입하여 min_heap을 만드는 함수
-parameter
	HeapType* h: node가 decrease할 heap
	int i: node가 decrease할 location
	int key: decrease할 node의 new key

6) void increase_key_min_heap(HeapType* h, int i, int key)
: heap의 node 안의 값보다 큰 값을 대입하여 min_heap을 만드는 함수
-parameter
	HeapType* h: node가 increase할 heap
	int i: node가 increase할 location
	int key: increase할 node의 new key

7) void print_heap(HeapType* h)
: heap을 출력하는 함수
-parameter
	HeapType* h: 출력할 heap

8) void main()
: test code

-----------------------------------------------------------------------------------------------------------
[Prim.c]
min-heap을 이용하여 prim's algorithm을 구현하는 프로그램

1) typedef struct element
-int edge: distance
-int vertex: vertex 넘버
-struct element* parent: parent vertex link

2) typedef struct HeapType
-element *heap[MAX_VERTICES + 1]: replace dist[]
-int heap_size

3) element* vertices[MAX_VERTICES]
: vertices list

4) void vertex_init(int num, HeapType* h)
: 각 vertex를 초기화하고, vertices[]와 heap에 넣는 함수
-parameter
	int num: vertex number와 index
	HeapType* h: vertex가 삽입될 heap

5) void build_min_heap(HeapType* h)
: min_heap을 만드는 함수
-parameter
	HeapType* h: min_heap을 구성할 heap

6) element* delete_min_heap(HeapType* h)
: min_heap에서 가장 작은 vertex를 delete하는 함수
-parameter
	HeapType* h: vertex가 delete될 heap

7) void decrease_key_min_heap(HeapType* h, int i, int key)
: heap의 node 안의 값보다 작은 값을 대입하여 min_heap을 만드는 함수
-parameter
	HeapType* h: node가 decrease할 heap
	int i: node가 decrease할 location
	int key: decrease할 node의 new key

8) int check(HeapType* h, int v)
: v가 vertex인 node가 있는지 확인하는 함수
-parameter
	HeapType* h: check할 heap
	int v: vertex number

9) int find_index(HeapType* h, int v)
: v가 vertex인 vertex의 index를 찾는 함수
-parameter
	HeapType* h: search할 heap
	int v: vertex number

10) void print_prim()
: MST를 preorder 순으로 출력하는 함수

11) void prim(int s, int n)
: prim's algorithm을 이용해 MST를 만드는 함수
-parameter
	int s: starting vertex
	int n: vertex 개수

11) void main()
: test code
