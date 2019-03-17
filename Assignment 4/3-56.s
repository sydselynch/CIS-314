	.file	"3-56.c"
	.section	.text.unlikely,"x"
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	loop
	.def	loop;	.scl	2;	.type	32;	.endef
	.seh_proc	loop
loop:
	.seh_endprologue
	movl	$-1, %eax
	cmpl	$1, %edx
	jle	.L2
	movl	$1, %r8d
	.p2align 4,,10
.L3:
	movl	%ecx, %r9d
	andl	%r8d, %r9d
	addl	$1, %r8d
	xorl	%r9d, %eax
	cmpl	%r8d, %edx
	jne	.L3
.L2:
	rep ret
	.seh_endproc
	.section	.text.unlikely,"x"
.LCOLDE0:
	.text
.LHOTE0:
	.ident	"GCC: (GNU) 5.4.0"
