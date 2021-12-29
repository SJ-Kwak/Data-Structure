#2076016_곽서진
[Doubly_linkedlist.c]

Doubly linked list의 맨 처음과 맨 뒤에 새로운 node를 삽입해주는 프로그램

1) typedef int element
: element를 정의

2) typedef struct DlistNode
-data: element
-*llink: left link
-*rlink: right link

3) void init(DlistNode* phead)
: Doubly linkedlist의 head note를 초기화하는 함수
-parameter
	DlistNode* phead: doubly linked list의 head node

4) void display(DlistNode* phead)
: linked list에 저장되어 있는 모든 node의 값을 <--- | p->data | --->의 형태로 하나씩 출력하는 함수
-parameter
	DlistNode* phead: doubly linked list의 head node

5) void dinsert_node(DlistNode* before, DlistNode* new_node)
: before와 new_node의 포인터를 인자로 받아 linked list의 원하는 위치에 node를 삽입하는 함수
-parameter
	DlistNode* before: 삽입하고자 하는 위치의 직전 node의 포인터
	DlistNode* new_node: 새롭게 삽입될 노드의 포인터

7) void main()
: test code. 'dinsert_node'를 통해 linked list를 생성하고 초기화하여 값을 삽입한다.
'dinsert_node'를 통해 linked list의 맨 처음에 10을, 맨 뒤에 20을 삽입한다.