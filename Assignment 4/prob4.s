	.file	"prob4.c"
	.text
	.globl	f
	.def	f;	.scl	2;	.type	32;	.endef
	.seh_proc	f
f:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %eax
	sall	$4, %eax
	popq	%rbp
	ret
	.seh_endproc
	.globl	g
	.def	g;	.scl	2;	.type	32;	.endef
	.seh_proc	g
g:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	%ecx, -64(%rbp)
	movl	%edx, -56(%rbp)
	movl	-64(%rbp), %ecx
	call	f
	movl	%eax, %ebx
	movl	-56(%rbp), %eax
	movl	%eax, %ecx
	call	f
	addl	%ebx, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 5.4.0"
