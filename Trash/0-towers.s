#function
	.globl	towers
#prologue
towers:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$0, %esp

	pushl	16(%ebp)
	pushl	20(%ebp)
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	call_towers
	pushl	16(%ebp)
	pushl	12(%ebp)
	call	print_move
	pushl	12(%ebp)
	pushl	16(%ebp)
	pushl	20(%ebp)
	pushl	8(%ebp)
	call	call_towers
#epilogue
	movl	%ebp, %esp
	popl	%ebp
	ret	

#function
	.globl	main
#prologue
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp

	movl	$3, -4(%ebp)
	pushl	-4(%ebp)
	call	print
	pushl	$3
	pushl	$2
	pushl	$1
	pushl	-4(%ebp)
	call	towers
#epilogue
	movl	%ebp, %esp
	popl	%ebp
	ret	

