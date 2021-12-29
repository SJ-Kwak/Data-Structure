[Transpose_matrix.c]

rows*cols 크기의 SparseMatrix B를 입력받아 transpose matrix를 출력하는 프로그램
행렬 B를 scanf를 통해 입력받지 않고, main()함수에 정의되어 있는 SparseMatrix 구조체 변수 B의 값을 이용합니다.
다른 행렬의 transpose matrix를 출력하고 싶다면 직접 main()함수의 B 값을 수정해주어야 합니다.

1) typedef struct { } element;
-row: non-zero element의 행 위치
-col: non-zero element의 열 위치
-value: non-zero element의 값

2) typedef struct SparseMatrix { } SparseMatrix;
-data: matrix에 있는 모든 non-zero element의 위치와 값을 저장한 구조체 배열
-rows: 전체 matrix 행의 크기
-cols: 전체 matrix 열의 크기
-terms: non-zero element의 개수

3) SparseMatrix transposeMatrix(SparseMatrix a)
: 인자로 전달된 matrix a의 transpose matrix b를 구하는 함수
input: SparseMatrix a
output: b (a의 transpose matrix)

4) void matrixPrint(SparseMatrix a)
: non-zero element만 저장된 SparseMatrix a를 dense matrix 형태로 출력해주는 함수
input: SparseMatrix a
output: return 값 없음

-------------------------------------------------------------------------------------
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
