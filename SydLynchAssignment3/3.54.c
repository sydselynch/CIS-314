#include <stdio.h>

int decode2(int x, int y, int z) {
	int op_1 = ((y-z) << 31) >> 31;
	int op_2 = x*(y-z);
	return op_1 | op_2;
}

int main() {
	printf("%d\n", decode2(1, 2, 4));
	printf("%d\n", decode2(-4, -8, -12));
}