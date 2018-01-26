	.comm	print, 4
#function
	.globl	main
#prologue
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$12, %esp

	movl	$1, -4(%ebp)
	movl	$2, -8(%ebp)
	movl	$3, -12(%ebp)
	pushl	-4(%ebp)
	pushl	-8(%ebp)
	pushl	-12(%ebp)
	call	print
#epilogue
	movl	%ebp, %esp
	popl	%ebp
	ret	

