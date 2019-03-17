#include <stdlib.h>
#include <stdio.h>

typedef struct ELE *tree_ptr;

struct ELE {
	long val;
	tree_ptr left;
	tree_ptr right;
};

long trace(tree_ptr tp) {
	long x = 0;  // initialize some variable that's in eax to 0
	while (tp != 0) {  // check if tp is 0 (testq)
		x = tp -> val;
		tp = tp -> right;
	}
	return x;
}

int main() {
	tree_ptr tp1 = malloc(sizeof(struct ELE));
	(*tp1).val = 5;
	tree_ptr tp2 = malloc(sizeof(struct ELE));
	(*tp2).val = 6;
	(*tp2).left = tp1;
	(*tp1).right = tp2;
	tree_ptr tp3 = malloc(sizeof(struct ELE));
	(*tp3).val = 7;
	(*tp3).left = tp2;
	(*tp2).right = tp3;

	printf("%x\n", trace(tp1));
	printf("%x\n", trace(tp2));
	}

/*
B. The function trace takes a tree pointer as an argument
	and returns a value of a node in the tree. If the tree
	pointer is 0, we simply return 0, otherwise we offset 
	our pointer by the pointer's value, and set our pointer
	to the next pointer which can be found by offsetting our
	current pointer by right. This will return the value of the
	rightmost treepointer.

*/