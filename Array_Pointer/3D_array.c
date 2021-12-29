//Assignment2(2) 2076016 °û¼­Áø
#include <stdio.h>
#include <stdlib.h>

double*** mem_alloc_3D_double(int a, int b, int c) {//dynamic memory allocation
	//a: depth, b: row, c: col
	double*** m = (double***)malloc(sizeof(double**) * a);//1D allocation

	for (int i = 0; i < a; i++) {
		*(m + i) = (double**)malloc(sizeof(double*) * b);//2D allocation
		for (int j = 0; j < b; j++) {
			*(*(m + i) + j) = (double*)malloc(sizeof(double) * c);//3D allocation
		}
	}
	return m;
}

void elements_3D(double*** m, int a, int b, int c) {//fill elements
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			for (int k = 0; k < c; k++) {
				*(*(*(m + i) + j) + k) = rand() % 100;//fill elements randomly 1~100
				printf("%.f ", *(*(*(m + i) + j) + k));
			}
			printf("\n");
		}
		printf("\n");
	}
}

void addition_3D(double*** m1, double*** m2, int a, int b, int c) {//addition of matrix m1 and m2
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			for (int k = 0; k < c; k++) {
				printf("%.f ", *(*(*(m1 + i) + j) + k) + *(*(*(m2 + i) + j) + k));
			}
			printf("\n");
		}
		printf("\n");
	}
}

void mem_dealloc_3D_double(double*** m) {//deallocation
	if (m != NULL) {
		free(m[0][0]);	//3D deallocation
		free(m[0]);		//2D deallocation
		free(m);		//1D deallocation
		m = NULL;
	}
}

void main() {
	//Define two matrices A and B using 'mem_alloc_3D_double'
	int x = 2, y = 3, z = 4;

	double*** A = mem_alloc_3D_double(x, y, z);
	double*** B = mem_alloc_3D_double(x, y, z);

	printf("Print out A\n");
	elements_3D(A, x, y, z);
	printf("Print out B\n");
	elements_3D(B, x, y, z);

	//Perform addition of two matrices using 'addition_3D()'
	printf("Addition of A and B\n");
	addition_3D(A, B, x, y, z);

	//Deallocate A and B
	mem_dealloc_3D_double(A);
	mem_dealloc_3D_double(B);
}