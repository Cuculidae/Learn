	.file	"code.c"
	.intel_syntax noprefix
	.globl	_accum
	.bss
	.align 4
_accum:
	.space 4
	.text
	.globl	_sum
	.def	_sum;	.scl	2;	.type	32;	.endef
_sum:
	push	ebp
	mov	ebp, esp
	sub	esp, 16
	mov	edx, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [ebp+12]
	add	eax, edx
	mov	DWORD PTR [ebp-4], eax
	mov	edx, DWORD PTR _accum
	mov	eax, DWORD PTR [ebp-4]
	add	eax, edx
	mov	DWORD PTR _accum, eax
	mov	eax, DWORD PTR [ebp-4]
	leave
	ret
	.ident	"GCC: (tdm-1) 5.1.0"
