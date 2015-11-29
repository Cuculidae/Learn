	.file	"comp.c"
	.text
	.globl	_comp
	.def	_comp;	.scl	2;	.type	32;	.endef
_comp:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movb	%dl, -4(%ebp)
	movb	%al, -8(%ebp)
	movzbl	-4(%ebp), %eax
	cmpb	-8(%ebp), %al
	setb	%al
	movzbl	%al, %eax
	leave
	ret
	.ident	"GCC: (tdm-1) 5.1.0"
