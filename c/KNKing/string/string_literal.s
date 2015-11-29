	.file	"string_literal.c"
	.globl	p
	.section .rdata,"dr"
.LC0:
	.ascii "one\0"
	.data
	.align 8
p:
	.quad	.LC0
	.globl	name
name:
	.ascii "two\0"
	.space 1
	.section .rdata,"dr"
.LC1:
	.ascii "three\0"
	.text
	.globl	f
	.def	f;	.scl	2;	.type	32;	.endef
	.seh_proc	f
f:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	leaq	.LC1(%rip), %rax
	movq	%rax, -8(%rbp)
	movl	$1920298854, -16(%rbp)
	movb	$0, -12(%rbp)
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 4.9.3"
