// CIS 314 Final Review

/*
S=2^S # of sets
E # of lines/set
B = 2^b black sign (bytes)
m = log_2(m) # of main memory adress bids

s = log_2(S) # of index bits
b = log_2(B) # of offset bits
t = m-(s+b) # of tag bits

2. Consider a 32-byte direct mapped cache with 4 byte blocks for an 8 bit machine (256 bytes of memory)

then S = 32/4 = 8
	 s = log_2(8) = 3 (2*2*2)
	 B = 4
	 b = log_2(4) = 2 (2*2)
	 m = 8

	 t = 8-(3+2) = 3


       t   s    b
	 [  ][  ][ ][ ]

*/

unsigned char getTag(unsigned char address) {
	
	return address >> 5;
}

unsigned char getSet(unsigned char address) {

	return (address << 3) >> 5;
}

unsigned char getOffset(unsigned char address) {

	return address & 0b00000011
}

void main() {
	
}

/*

- minimize calls to length(b)

void foo(int *a, int *b, int i, int n) {
	int lengthB = length(b);
	for (int j = 0; j < lengthB; ++j) {
		...
	}
}

- minimize multiplications

void foo(int *a, int *b, int i, int n) {
	int lengthB = length(b);
	int in = i*n;
	for (int j = 0; j < lengthB; ++j) {
		a[in] += b[in + j];
	}
}

- minimize memory writes

void foo(int *a, int *b, int i, int n) {
	int lengthB = length(b);
	int in = i*n;
	int sum = a[in];
	for (int j = 0; j < lengthB; ++j) {
		sum += b[in + j];
	}
	a[in] = sum;
}

Why won't the compiler optimize out the length(b) calls?

	the compiler doesn't know that length(b) is modifying some other length(b)

Why won't it optimize out the memory writes?

	pg 478




2c.
	
	0x04 = 0000 0100 t=0, s=1, b=0    miss (cache is empty) then cache becomes (0x04)(0x05)(0x06)(0x07) because it fills with what it missed and the next 3

	0x06 = 0000 0110 t=0, s=1, b=2	  hit

	0x10 = 0001 0000 t=0, s=4, b=0    miss cold miss

	0x24 = 0010 0100 t=1, s=1, b=0    miss tag mismath

	0x06 = 0000 0110 t=0. s=1. b=2    miss tag mismatch

	0x26 = 0010 0110 t=1, s=1, b=2    miss tag mismatch



	Using two-way associative cache

	s[i] has tag = 0 and tag = 1
	0x04 cold miss
	0x06 hit
	0x10 cold miss
	0x24 cold miss
	0x06 hit
	0x26 hit

	cachea after first miss = (0x04)(0x05)(0x06)(0x07)
	cache after missing 24 with tag 1 which was unused (0x04)(0x05)(0x06)(0x07) and (0x24)(0x25)(0x26)(0x27)
	we have more room in the cache with two tags


3.

xorl %ecx, %edx

F - Fetch - icode:ifun = m0[]
			rA:rB = m1[]
			pC ++
D - Decode - rA <- %ecx
			 rB <- %edx
E - Execute - valE <- rA xorl rB
M - Memory - nothing is written
W - Write  - rB <- valE

4. 

xorl %ecx, %edx

icode:ifun    ecx    edx
  6     3     1      2



7.

if asked to do stalls, do bubbles not nops

mrmovl 0(%eax), %ebx
addl %ecx, %edx
andl %ebx, %edx

How many stalls required without data forwarding?

in addl, ecx and edx are not used in previous line so no problem
in andl, we reference previously used register

F D E M W | ebx
  F D E M W | edx
    F D E M W
      ->->->

Need two bubbles to allow the first instruction to do writeback 
Need another to allow for edx to be done
mrmovl
addl
bubble
bubble
bubble
andl

with forwarding?

F D E|ebx M W
  F D E|edx M W
    F D E M W
      -> 
one bubble required

8)

Why do all modern processors use memory hierarchy consisting of multiple levels of cache?


*/