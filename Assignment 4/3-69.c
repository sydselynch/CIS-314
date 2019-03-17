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

	printf("%x\n", trace(tp1));
	}