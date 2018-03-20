		.data
	Switch:   .word L1,L2,L3,L4
	Welcome: .asciiz "Welcome to Project \n"
	MainMenu: .asciiz "\n Main Menu:\n  1.Build a min-heap\n  2.Evaulate an expression\n  3.Construct a 2D array\n  4.Exit\n  Please Select an Option: "
	Q1: .asciiz "MinHeap"
	Q2: .asciiz "String Evaulate"
	Q3: .asciiz "Array Create"
	END: .asciiz "Program ends. Bye :)"
		.text
		.globl main
main:  li,$v0,4 #print String
	   la,$a0,Welcome
	   syscall
	   
LOOP:  li $v0,4
	   la $a0,MainMenu
	   syscall
	   li $v0,5 #read integer
	   syscall
	  
	   addi $t1,$v0,-1
	   sll,$t2,$t1,2
	   la $t0,Switch
	   add $t3,$t2,$t0
	   lw $t4,0($t3)
	   jr $t4
	   
	   
L1: li $v0,4
	la $a0,Q1
	syscall
	j LOOP
	
l2: li $v0,4
	la $a0,Q2
	syscall
	j LOOP	
	
L3: li $v0,4
	la $a0,Q3
	syscall
	j LOOP	
	
L4:li $v0,4
	la $a0,END
	syscall
	j EXIT	
	
EXIT:li $v0,10
	 syscall
	   