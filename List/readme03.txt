#2076016_곽서진
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