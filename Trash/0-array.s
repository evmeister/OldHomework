	.comm	a, 4
	.comm	init_array, 4
#function
	.globl	main
#prologue
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp

	movl	$10, -4(%ebp)
	pushl	-4(%ebp)
	call	init_array
	pushl	-4(%ebp)
	call	print_array
#epilogue
	movl	%ebp, %esp
	popl	%ebp
	ret	

