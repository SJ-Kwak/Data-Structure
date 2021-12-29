#2076016_곽서진
[3D_array.c]

double형 3차원 matrix 두 개의 메모리를 동적으로 할당하고, 두 matrix의 합을 계산하여 출력하는 프로그램
scanf를 통해 따로 입력값을 받지 않고, 1~100까지의 정수 중 난수를 생성하여 matrix에 입력합니다.

1) double*** mem_alloc_3D_double(int a, int b, int c)
: 3차원 배열의 크기(a*b*c)만큼 메모리를 할당하는 함수

2) void elements_3D(double*** m, int a, int b, int c)
: 1~100 사이의 정수인 난수를 생성하여 3차원 배열에 저장하고, 그 배열을 출력하는 함수

3) void addition_3D(double*** m1, double*** m2, int a, int b, int c)
: 3차원 배열 m1과 m2의 덧셈을 수행하여 출력하는 함수

4) void mem_dealloc_3D_double(double*** m)
: 3차원 배열에 할당했던 메모리를 해제하는 함수