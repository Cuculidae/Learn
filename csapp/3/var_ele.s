	.file	"var_ele.c"
	.text
	.globl	_var_ele
	.def	_var_ele;	.scl	2;	.type	32;	.endef
_var_ele:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	8(%ebp), %eax
	leal	-1(%eax), %edx
	movl	%edx, -4(%ebp)
	movl	%eax, %edx
	movl	16(%ebp), %eax
	imull	%edx, %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%eax, %edx
	movl	20(%ebp), %eax
	movl	(%edx,%eax,4), %eax
	leave
	ret
	.ident	"GCC: (tdm-1) 5.1.0"
