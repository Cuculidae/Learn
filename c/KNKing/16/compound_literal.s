	.file	"compound_literal.c"
	.text
	.globl	f
	.def	f;	.scl	2;	.type	32;	.endef
	.seh_proc	f
f:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$528, -32(%rbp)
	movabsq	$7598245611731904836, %rax
	movq	%rax, -28(%rbp)
	movq	$25974, -20(%rbp)
	movl	$0, -12(%rbp)
	movb	$0, -8(%rbp)
	movl	$10, -4(%rbp)
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 4.9.3"
