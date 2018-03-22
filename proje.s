.data
	SWITCH:		.word L1,L2,L3,L4
	Q3Array:	.space 1000 #space

	num:	    .word 0, 0  # i want to store my two numbers here

	Welcome: 	.asciiz "Welcome to Project \n"
	MainMenu: 	.asciiz "\n Main Menu:\n  1.Build a min-heap\n  2.Evaulate an expression\n  3.Construct a 2D array\n  4.Exit\n  Please Select an Option: "
	Q1str1: 	.asciiz "MinHeap\n"
	Q2str1: 	.asciiz "String Evaulate\n"
	Q3str1:		.asciiz "Array Create\n"
	Q3str2:		.asciiz "Enter the input string:"
	END: 		.asciiz "Program ends. Bye :)"
    
.text
	.globl main
main:
	li,$v0,4 #print String
	la,$a0,Welcome	#
	syscall			#
MAINLOOP:
	li $v0,4		#
	la $a0,MainMenu	#
	syscall			#
	li $v0,5		#read integer
	syscall			#
	addi $t1,$v0,-1	#
	sll,$t2,$t1,2	#
	la $t0,SWITCH	#load menu string
	add $t3,$t2,$t0	#
	lw $t4,0($t3)	#
	jr $t4			#
L1: 
	li $v0,4		#
	la $a0,Q1str1	#load Q3 string
	syscall			#
	j MAINLOOP		#
L2: 
	li $v0,4		#
	la $a0,Q2str1	#load Q3 string
	syscall			#
	j MAINLOOP		#
L3: 
	li $v0,4		#
	la $a0,Q3str1   #load Q3 string
	syscall 		#print 
	li $v0,4		#
	la $a0,Q3str2	#
	syscall			#
	la $a0,Q3Array	#
	li $t0, 0		#
	j MAINLOOP		#
L4:
	li $v0,4		#
	la $a0,END		#
	syscall			#
	j EXIT			#


EXIT:
	li $v0,10		# 
	syscall			#
	   
