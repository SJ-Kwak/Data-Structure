//Assignment2(1) 2076016 °û¼­Áø
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 10

typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;	//row size
	int cols;	//column size
	int terms;	//the number of elements(non-zero)
} SparseMatrix;

SparseMatrix transposeMatrix(SparseMatrix a) { //transpose
	SparseMatrix b; //transpose matrix of a
	int idx = 0;//variable to access the data from b in order
	//alter row and col size, and set each of them as a size of b
	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;//same number

	if (a.terms > 0) {
		for (int i = 0; i < a.cols; i++) {
			for (int j = 0; j < a.terms; j++) {
				if (a.data[j].col == i) {//change col and row
					b.data[idx].row = a.data[j].col;
					b.data[idx].col = a.data[j].row;
					b.data[idx].value = a.data[j].value;
					idx++;
				}
			}
		}
	}
	return b;
}

void matrixPrint(SparseMatrix a) { //print out
	int k = 0, t = 0;
	int i, j;
	for (i = 0; i < a.rows; i++) {
		for (j = 0; j < a.cols; j++) {
			if (a.data[k].row == i && a.data[k].col == j) {//non-zero
				printf("%d ", a.data[k].value);
				k++;
			}
			else {//zero
				printf("%d ", 0);
			}
			t++;
			if (t % a.cols == 0)
				printf("\n"); //if t becomes multiple of a.cols, next line
		}
	}
}

void main() {
	//Add B as an input. Use your own example freely.
	SparseMatrix B = {
		{ {0,3,7}, {1,0,9}, {1,5,8}, {3,0,6}, {3,1,5}, {4,5,1}, {5,2,2} },//input value
		6,6,7//rows, cols, terms
	};

	//Perform the transpose operation
	SparseMatrix BT;
	BT = transposeMatrix(B);

	//Print out B and B^T in an dense matrix form to check whether the operation works correctly.
	printf("Print out B\n");
	matrixPrint(B);
	printf("------------------------\n");
	printf("Print out B^T\n");
	matrixPrint(BT);

}