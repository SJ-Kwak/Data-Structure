#2076016_곽서진
[linked_stack.cpp]

Simply linked list로 구현된 Linked stack을 Circular doubly linked list로 바꾸어 코드 작성

1) typedef int element
: element를 정의

2) typedef struct DlistNode
-item: stack에 저장할 element
-*llink: left link
-*rlink: right link

3) typedef struct LinkedStackType
-DlistNode* top: stack의 top node

4) void init(LinkedStackType* s, DlistNode* head)
: stack을 초기화하는 함수
-parameters
	LinkedStackType *s: 초기화할 stack
	DlistNode* head: s의 head node

5) int is_empty(LinkedStackType* s, DlistNode* head)
: stack이 비었는지 확인하는 함수
-parameters
	LinkedStackType *s: 확인할 stack
	DlistNode* head: s의 head node

6) void push(LinkedStackType* s, element item)
: stack에 item을 삽입하는 함수
-parameters
	LinkedStackType *s: item을 삽입할 stack
	element item: stack에 삽입할 item

7) element pop(LinkedStackType* s, DlistNode *head)
: stack에서 top node를 제거하는 함수
-parameters
	LinkedStackType *s: top node를 제거할 stack
	DlistNode* head: s의 head node

8) element peek(LinkedStackType* s, DlistNode* head)
: stack에서 top node를 제거하지 않고 data만 반환하는 함수
-parameters
	LinkedStackType *s: top node의 data를 반환할 stack
	DlistNode* head: s의 head node

9) void main()
: test code.