	.comm	y, 4
	.comm	z, 4
	.comm	x, 4
#function
	.globl	foo
#prologue
foo:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$0, %esp

	movl	$1, x
	movl	$2, y
	movl	$3, z
#epilogue
	movl	%ebp, %esp
	popl	%ebp
	ret	

