	.file	"arith.c"
	.text
	.globl	_arith
	.def	_arith;	.scl	2;	.type	32;	.endef
_arith:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%ebp)
	movl	16(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	movl	%eax, -8(%ebp)
	movl	-4(%ebp), %eax
	movzwl	%ax, %eax
	movl	%eax, -12(%ebp)
	movl	-8(%ebp), %eax
	imull	-12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	leave
	ret
	.ident	"GCC: (tdm-1) 5.1.0"
