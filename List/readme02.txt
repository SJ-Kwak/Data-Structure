#2076016_곽서진
[Merge_linkedlist.c]

Linked list A와 B를 합쳐 C라는 linked list를 생성한 후, 오름차순으로 배열하는 프로그램
merge하고자 하는 linked list를 따로 입력받지 않고 예시로 주어진  a = { 1,2,5,10,15,20,25 }, b = { 3,7,8,15,18,30 }를 사용합니다.
다른 두 list의 결과를 구하고 싶다면, main() 함수에 정의되어 있는 a[], b[] 배열을 수정하여 사용해주세요.
단, 정수 배열 a와 b는 오름차순으로 정렬되어 있어야 정상적인 결과가 출력됩니다.

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