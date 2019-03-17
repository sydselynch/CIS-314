#include <stdio.h>
#include <stdlib.h>


int * bubbleSort(int *array, int n) {
	int temporary;
	int swap = 1;
	while (swap == 1) {
		swap = 0;
		for (int i=0; i<(n-1); ++i) {
			if (array[i] > array[i+1]) {
				temporary = array[i];
				array[i] = array[i+1];
				array[i+1] = temporary;
				swap = 1;			// If a swap does happen, swap = 1 and loop continues
			}
		}
	}
	return array;
}

int main() {
	int length;
	int input;

	printf("Enter an array length as an integer:\n");
	scanf("%d", &length);

	int* array = malloc(length * sizeof(int));
	for (int i=0; i<length; i++) {
		printf("Enter an integer to put in the array:\n");
		scanf("%d", &input);
		array[i] = input;
	}
	printf("Inputted array:\n");
	for (int i=0; i<length; i++){
		printf("%X\n", array[i]);
	}
	printf("\n");
	array = bubbleSort(array, length);
	printf("Sorted array:\n");
	for (int i=0; i<length; i++) {
		printf("%X\n", array[i]);
	}

	free(array);
}