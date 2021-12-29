[selection_sort.c]
Selection sort 구현하는 프로그램

1) typedef struct data
-int *id
-int* scord

2) #define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
: t를 사용해서 x와 y를 swap하는 함수

3) void selection_sort_stable(data* list, int n)
: selection sort로 stable한 sort를 만드는 함수
-parameter
	data* list: sort할 array
	int n: list의 length

4) int main()
: test code

-------------------------------------------------------------------------
[radix_sort.c]
Counting sort를 이용하여 Radix sort를 구현하는 프로그램

1) #define MAX 1000
: input data 개수

2) void gen_rand(int A[])
: input data를 random으로 생성하는 함수
-parameter
	int A[]: random input data를 저장하는 배열

3) int get_max(int A[])
: 인자 배열의 가장 큰 값을 찾는 함수
-parameter
	int A[]: 가장 큰 값을 찾을 배열

4) void counting_sort(int A[], int n)
: counting sort를 구현하는 함수
-parameter
	int A[]: counting sort에 의해 정렬될 배열
	int n: digits == r로 나눌 지수

5) void radix_sort(int A[])
: counting sort를 이용하여 radix sort를 구현하는 함수
-parameter
	int A[]: radix sort에 의해 정렬될 배열

6) void print(int A[])
: 배열을 출력하는 함수
-parameter
	int A[]: 출력할 배열

7) int main()
: test code
