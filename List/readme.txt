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

--------------------------------------------------------------------------------------
[Merge_linkedlist.c]

Linked list A와 B를 합쳐 C라는 linked list를 생성한 후, 오름차순으로 배열하는 프로그램

1) typedef int element
: element를 정의

2) typedef struct ListNode
-data: element
-*link: ListNode의 link

3) typedef struct ListType
-length: list의 길이
-*head: list의 head
-*tail: list의 tail

4) void init(ListType* list)
: 인자로 전달된 linked list의 length, head, tail을 초기화하는 함수
-parameter
	ListType* list: 초기화할 linked list의 주소값

5) void insert_last(ListType* list, element data)
: linked list의 가장 마지막 node에 data를 삽입하는 함수
-parameter
	ListType* list: node를 삽입할 list
	element data: 삽입할 node의 data

6) void merge_list(ListType* list1, ListType* list2, ListType* list3)
: linked list1과 2에 저장된 값을 오름차순으로 list3에 추가해주는 함수
-parameter
	ListType* list1: merge할 list 'a'
	ListType* list2: merge할 list 'b'
	ListType* list3: merge한 list

7) void display(ListType* list)
: linked list에 저장되어 있는 모든 node의 값을 { p->data.... }의 형태로 출력하는 함수
-parameter
	ListType* list: 출력할 linked list의 주소값

8) void main()
: test code. linked list A, B, C를 동적 할당하여 생성한다. A와 B에 예시값 배열을 삽입할 때 'insert_last' 함수를 활용한다.
'merge_list'를 통해 A와 B를 merge하고, C에 저장한 결과값을 출력한다.

-----------------------------------------------------------------------------------------------
[ListADT.c]

주어진 list ADT를 이용하여 예제 코드를 실행할 수 있는 함수를 구현한 프로그램

1) typedef int element
: element를 정의

2) typedef struct ListNode
-data: element
-*link: ListNode의 link

3) typedef struct ListType
-length: list의 길이
-*head: list의 head
-*tail: list의 tail

4) void error(char* message)
: 오류 메시지 출력 함수
-parameter
	char* message: 출력할 메시지

5) void init(ListType* list)
: 인자로 전달된 linked list의 length, head, tail을 초기화하는 함수
-parameter
	ListType* list: 초기화할 linked list의 주소값

6) int is_empty(ListType* list)
: linked list가 비어있는지 확인하여, 비어있으면 1(TRUE) 아니면 0(FALSE)를 리턴하는 함수
-parameter
	ListType* list: 비어있는지 확인할 list

7) int get_length(ListType* list)
: 전체 node의 개수를 알려주는 함수
-parameter
	ListType* list: 개수를 구할 list

8) ListNode* get_node_at(ListType* list, int pos)
: 인자로 들어온 list의 pos번째 node를 찾아 node의 포인터를 리턴하는 함수
-parameter
	ListType* list: node를 찾을 list
	int pos: 찾을 node의 위치

9) element get_entry(ListType* list, int pos)
: pos번째 node의 data값을 리턴하는 함수
-parameter
	ListType* list: node를 찾을 list
	int pos: 찾을 node의 위치

10) void display(ListType* list)
: linked list에 있는 모든 node의 data값을 차례로 출력하는 함수
-parameter
	ListType* list: 출력할 list

11) int is_in_list(ListType* list, element item)
: item값과 일치하는 data값을 가지는 node가 있는지 탐색하여, 있으면 1(TRUE) 아니면 0(FALSE)를 리턴하는 함수
-parameter
	ListType* list: item이 있는지 확인할 list
	element item: 확인할 item

12) void insert_node(ListType* list, ListNode* before, ListNode* new_node)
: 인자로 입력받은 list의 before 다음에 new_node를 삽입하는 함수
-parameter
	ListType *list: node를 삽입할 list
	ListNode* before: 삽입할 위치의 직전 node의 포인터
	ListNode* new_node: 새로 삽입할 node의 포인터

13) void add(ListType* list, int pos, element data)
: linked list의 특정 pos에 data를 삽입하는 함수
-parameter
	ListType* list: node를 삽입할 list
	int pos: 삽입할 node의 위치
	element data: 삽입할 node의 data

14) void add_first(ListType* list, int value)
: linked list의 맨 앞에 node를 삽입하는 함수
-parameter
	ListType* list: node를 삽입할 list
	int value: 삽입할 node의 data

15) void add_last(ListType* list, int value)
: linked list의 맨 뒤에 node를 삽입하는 함수
-parameter
	ListType* list: node를 삽입할 list
	int value: 삽입할 node의 data

16) void remove_node(ListType *list, ListNode* before, ListNode* removed)
: 인자로 입력받은 list의 before 다음에 new_node를 제거하는 함수
-parameter
	ListType *list: node를 제거할 list
	ListNode* before: 제거할 위치의 직전 node의 포인터
	ListNode* new_node: 제거할 node의 포인터

17) void delete(ListType* list, int pos)
: linked list의 특정 pos의 node를 제거하는 함수
-parameter
	ListType* list: node를 제거할 list
	int pos: 제거할 node의 위치

18) void delete_first(ListType* list)
: linked list의 맨 앞에 node를 제거하는 함수
-parameter
	ListType* list: node를 제거할 list

19) void delete_last(ListType* list)
: linked list의 맨 뒤에 node를 제거하는 함수
-parameter
	ListType* list: node를 제거할 list

20) void main()
: test code
