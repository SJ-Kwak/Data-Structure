#2076016_곽서진
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