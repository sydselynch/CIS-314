#include <stdio.h>

struct cache_block {
	unsigned char valid = 0;
	unsigned int tag;
	unsigned int value;

}



unsigned char getTag(unsigned char address) {
	
	return address >> 5;
}

unsigned char getSet(unsigned char address) {

	return (address << 3) >> 5;
}

unsigned char getOffset(unsigned char address) {

	return address & 0b00000011;
}



void main(){

	char hexAddress[32], hexValue[32];
	printf("Enter a 32-bit hex address");
	scanf("%x", hexAddress);
	printf("Enter a 32-bit hex value");
	scanf("%x", hexValue);

}