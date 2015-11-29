	.file	"simple.c"
	.text
	.globl	_simple
	.def	_simple;	.scl	2;	.type	32;	.endef
_simple:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%ebp)
	movl	8(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	movl	-4(%ebp), %eax
	leave
	ret
	.ident	"GCC: (tdm-1) 5.1.0"
