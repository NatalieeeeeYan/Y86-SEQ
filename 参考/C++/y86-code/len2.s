	.file	"len2.c"
	.text
	.p2align 4,,15
	.globl	len2
	.type	len2, @function
len2:
.LFB0:
	.cfi_startproc
	movl	4(%esp), %edx
	xorl	%eax, %eax
	movl	(%edx), %ecx
	testl	%ecx, %ecx
	je	.L2
	.p2align 4,,7
	.p2align 3
.L3:
	addl	$1, %eax
	movl	(%edx,%eax,4), %ecx
	testl	%ecx, %ecx
	jne	.L3
.L2:
	rep
	ret
	.cfi_endproc
.LFE0:
	.size	len2, .-len2
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
