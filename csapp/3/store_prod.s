	.file	"store_prod.c"
	.section	.text.unlikely,"x"
LCOLDB0:
	.text
LHOTB0:
	.p2align 4,,15
	.globl	_store_prod
	.def	_store_prod;	.scl	2;	.type	32;	.endef
_store_prod:
	pushl	%esi
	movl	12(%esp), %eax
	movl	20(%esp), %esi
	movl	8(%esp), %ecx
	imull	%eax, %esi
	mull	16(%esp)
	addl	%esi, %edx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	popl	%esi
	ret
	.section	.text.unlikely,"x"
LCOLDE0:
	.text
LHOTE0:
	.ident	"GCC: (tdm-1) 5.1.0"
