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

---------------------------------------------------------------
[Simulation.cpp]

Bank staff가 1->2명으로 늘어났을 때 Simulation 결과를 구하는 코드 작성

1) typedef struct element
-id: 고객 id
-arrival_time: 고객이 도착한 시간
-service_time: 고객이 service를 받은 시간

2) typedef struct QueueType
-queue[MAX_SIZE]: 대기하는 고객을 저장할 queue
-front, rear: queue의 맨앞과 맨뒤

3) double random()
: 0과 1 사이의 실수 중 랜덤으로 반환하는 함수

*Global variables*
-QueueType queue: 대기 중인 고객을 저장할 queue
-int duration = 20: 총 Simulation 시간. 유의미한 결과를 낳기 위해 duration을 20으로 증가시킴.
-double arrival_prob = 0.7: 하나의 시간 unit안에 도착하는 평균 고객의 수
-int max_serv_time = 5: 한 고객 당 최대 service 제공 시간
-int clock
-int customers: 총 고객 수
-int served_customers: service를 제공한 총 고객 수
-int waited_time: 고객이 기다린 시간

4) int is_empty(QueueType* q)
: q가 비었는지 확인하는 함수. 비었으면 front==rear 반환
-parameter
	QueueType* q: 확인할 queue

5) int is_full(QueueType* q)
: queue가 꽉 찼는지 확인하는 함수. 꽉 찼으면 front == (rear+1)%MAX_QUEUE_SIZE 반환
-parameter
	QueueType* q: 확인할 queue

6) void enqueue(QueueType* q, element item)
: queue에 item을 삽입하는 함수
-parameter
	QueueType* q: 삽입할 queue
	element item: 삽입할 item

7) element dequeue(QueueType* q)
: queue에서 item을 제거하는 함수
-parameter
	QueueType* q: 삽입할 queue
	element item: 삽입할 item

8) int is_customer_arrived()
: 고객이 왔는지 확인하는 함수

9) void insert_customer(int arrival_time)
: 새로운 고객을 queue에 삽입하는 함수
-parameter
	int arrival_time: 고객이 도착한 시간

10) int remove_customer()
: queue에서 고객을 제거하고 고객이 기다린 시간과 고객의 서비스가 시작한 시각을 알려주는 함수

11) void print_stat()
: 서비스 종료 후 결과를 출력하는 함수

12) void main()
: test code.
service_time을 배열로 선언하여, clock이 duration시간보다 작을 동안, while loop을 지속한다.
While문 내에서는 고객이 도착한 현재 시각 clock을 인자로 받아 insert_customer으로 queue에 삽입한다.
2명의 staffs에 대해 고객이 각 staff에게 service를 받고 있는지를 확인한다.
한 명의 staff에게라도 서비스를 받는 고객이 없다면, remove_customer함수를 통해 queue에서 기다리는 고객을 제거하여 서비스를 받게 한다.
