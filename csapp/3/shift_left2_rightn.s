	.file	"shift_left2_rightn.c"
	.text
	.globl	_shift_left2_rightn
	.def	_shift_left2_rightn;	.scl	2;	.type	32;	.endef
_shift_left2_rightn:
	pushl	%ebp
	movl	%esp, %ebp
	sall	$2, 8(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	sarl	%cl, 8(%ebp)
	movl	8(%ebp), %eax
	popl	%ebp
	ret
	.ident	"GCC: (tdm-1) 5.1.0"
