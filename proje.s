.data
	SWITCH:		.word L1,L2,L3,L4
	Q3Array:	.space 1000 #space

	num:	    .word 0, 0  # i want to store my two numbers here
	buffer:     .space    1


	Welcome: 	.asciiz "Welcome to Project \n"
	MainMenu: 	.asciiz "\n Main Menu:\n  1.Build a min-heap\n  2.Evaulate an expression\n  3.Construct a 2D array\n  4.Exit\n  Please Select an Option: "
	Q1str1: 	.asciiz "MinHeap\n"
	Q2str1: 	.asciiz "String Evaulate\n"
	Q3str1:		.asciiz "Array Create\n"
	Q3str2:		.asciiz "Enter the input string:"
	newLine:	.asciiz "\n"
	END: 		.asciiz "Program ends. Bye :)"
    
.text
	.globl main
main:
	li,$v0,4 			# print string mode
	la,$a0,Welcome		# address of string in memory
	syscall				# 
MAINLOOP:
	li $v0,4			# print string mode
	la $a0,MainMenu		# load address of string "MainMenu" in memory
	syscall				# 
	li $v0,5			# print integer mode
	syscall				#
	addi $t1,$v0,-1		# 
	sll,$t2,$t1,2		# 
	la $t0,SWITCH		# load address of string "SWITCH" in memory
	add $t3,$t2,$t0		# 
	lw $t4,0($t3)		# 
	jr $t4				# jump to the addres stored in register t4
L1: 	
	li $v0,4			# print string mode
	la $a0,Q1str1		# load address of string "Q1str1" in memory
	syscall				#
	j MAINLOOP			# jump to MAINLOOP label
L2: 	
	li $v0,4			# print string mode
	la $a0,Q2str1		# load address of string "Q2str1" in memory
	syscall				#
	j MAINLOOP			# jump to MAINLOOP label
L3: 
	li $v0,4			# print string mode
	la $a0,Q3str1   	# load address of string "Q3str1" in memory
	syscall 			# 
	li $v0,4			# print string mode
	la $a0,Q3str2		# load address of string "Q3str2" in memory
	syscall				# 
	li $v0,8			# read string mode
	la $a0,buffer		# load address of string "buffer" in memory
	li $a1,100			# load immediate 100 to argument register 1 as char lenght
	syscall
	la $a0, newLine		# load address of string "newLine" in memory
	li $v0, 4     		# print string mode
	syscall				
	la $a0, buffer     	# load address of string "buffer" in memory
	li $v0, 4     		# print string mode
	syscall



	j MAINLOOP			# jump to MAINLOOP label
L4:
	li $v0,4			# print string mode
	la $a0,END			# load address of string "END" in memory
	syscall				# 
	j EXIT				# jump to EXIT label


EXIT:
	li $v0,10			# exit mode
	syscall				#
	   
