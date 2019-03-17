#include <stdio.h>

#define M 13
typedef int Marray_t[M][M];

void transpose(Marray_t A) {
	int i, j;
	for (i = 0; i < M; i++) {
		for (j = 0; j < i; j++) {
			int t = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = t;
		}
	}
}

void transposeOptimized(Marray_t A) {
	int i, j;
	int *columnInitial = &A[0][0];
	for (i = 0; i < M; i++) {
		for (j = 0; j < i; j++) {
			int *row  = columnInitial + (i*M+j);   // We use pointer arithmetic to switch the values
            int *col = columnInitial + (j*M+i);
            int t = *row;  // temp
            *row = *col;
            *col = t;
		}
	}
}

void printArray(Marray_t A) {
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < M; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}

void main() {
	Marray_t array1 = {{0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12}};
	printArray(array1);
	transpose(array1);
	printArray(array1);
	Marray_t array2 = {{0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12},
				  {0,1,2,3,4,5,6,7,8,9,10,11,12}};
	transposeOptimized(array2);
	printArray(array2);
}