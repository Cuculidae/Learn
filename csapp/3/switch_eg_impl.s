	.file	"switch_eg_impl.c"
	.text
	.globl	_switch_eg_impl
	.def	_switch_eg_impl;	.scl	2;	.type	32;	.endef
_switch_eg_impl:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	12(%ebp), %eax
	subl	$100, %eax
	movl	%eax, -8(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	cmpl	$6, -8(%ebp)
	ja	L11
	movl	-8(%ebp), %eax
	movl	_jt.1484(,%eax,4), %eax
	nop
	jmp	*%eax
L11:
	nop
L3:
	movl	$0, -4(%ebp)
	jmp	L5
L6:
	movl	-4(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, -4(%ebp)
	jmp	L5
L7:
	addl	$10, -4(%ebp)
L8:
	addl	$11, -4(%ebp)
	jmp	L5
L9:
	movl	-4(%ebp), %eax
	imull	-4(%ebp), %eax
	movl	%eax, -4(%ebp)
	nop
L5:
	movl	-4(%ebp), %eax
	leave
	ret
	.data
	.align 4
_jt.1484:
	.long	L6
	.long	L3
	.long	L7
	.long	L8
	.long	L9
	.long	L3
	.long	L9
	.ident	"GCC: (tdm-1) 5.1.0"
