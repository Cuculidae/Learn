	.file	"test.c"
	.text
	.globl	_test
	.def	_test;	.scl	2;	.type	32;	.endef
_test:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	8(%ebp), %eax
	movw	%ax, -4(%ebp)
	cmpw	$0, -4(%ebp)
	setne	%al
	movzbl	%al, %eax
	leave
	ret
	.ident	"GCC: (tdm-1) 5.1.0"
