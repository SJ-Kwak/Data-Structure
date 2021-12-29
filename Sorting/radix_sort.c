#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000 //# of input data

void gen_rand(int A[]) { //generate the input data randomly

	for (int i = 0; i < MAX; i++) {
		int n = 0, m = 1;
		for (int j = 0; j < 24; j++) {
			int rd = rand() % 2;
			if (rd == 1)
				n += m;
			m *= 2;
		}
		A[i] = n;
	}
}

int get_max(int A[]) {
	int max = A[0];

	for (int i = 1; i < MAX; i++) {
		if (max < A[i])
			max = A[i];
	}

	return max;
}

void counting_sort(int A[], int n) {
	int B[MAX];
	int C[64] = { 0 };

	for (int i = 0; i < MAX; i++) {//increase count num
		C[(A[i] / n) % 64]++;
	}

	for (int i = 1; i < 64; i++) {//accumulate
		C[i] += C[i - 1];
	}

	for (int i = MAX - 1; i >= 0; i--) {
		B[C[(A[i] / n) % 64] - 1] = A[i];
		C[(A[i] / n) % 64]--;
	}

	for (int i = 0; i < MAX; i++) {
		A[i] = B[i];
	}
}

void radix_sort(int A[]) {
	int max = get_max(A);

	for (int i = 1; max / i > 0; i *= 64) {
		counting_sort(A, i);
	}
}

void print(int A[]) {
	for (int i = 0; i < MAX; i++)
		printf("%8d  ", A[i]);
}

int main() {
	srand((unsigned)time(NULL));
	int arr[MAX];
	gen_rand(arr);
	print(arr);
	printf("\n");
	printf("--------------------------------------------------SORTED------------------------------------------------------");
	printf("\n");
	radix_sort(arr);
	print(arr);
}