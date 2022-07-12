.data
str:		.string 	"sort\n"
delimiter:  .string     "  "
newline:	.string		"\n"
array:      .word       20, 37, 1, 73, 2, 12, 43, 86, 57, 77
length:     .word       10
size:       .word       4


.text
main:
    la a0, str
    li a7, 4
    ecall

	jal init
    jal loopPrint

	jal init

	li a7, 4
    la a0, newline
    ecall
	
	# ???¨°???
	andi t0, a0, 0
	addi t2, a1, 0
	jal sort
	
	jal init
	jal loopPrint
	li a7, 10
    ecall

init:
	la a1, length
	lw a1, 0(a1)
    la a2, array
    la a3, size
	lw a3, 0(a3)	
	jr x1
	
loopPrint:
    andi t0, a0, 0
    addi t1, a1, 0
	loop:
    	mul t2, a3, t0
    	add t2, t2, a2
    	lw a0, 0(t2)
    	li a7, 1
    	ecall
    	# Print a delimiter between the numbers
    	li a7, 4
    	la a0, delimiter
    	ecall
    	# Increment	
    	addi t0, t0, 1
	    blt  t0, t1, loop
    jr x1

sort:
	andi t1, a0, 0
	addi t1, t1, 1
	sort_in:		
		mul a0, t1, a3
		add a0, a2, a0 
		lw a4, 0(a0)
		addi t1, t1, -1
		mul a0, t1, a3
		add a0, a2, a0
		lw a5, 0(a0)
		bge a5 ,a4, judge
		sw a4, 0(a0)
		addi t1, t1, 1
		mul a0, t1, a3
		add a0, a2, a0 
		sw a5, 0(a0)
		addi t1, t1, -1
		judge:
		addi t1, t1, 2
		blt t1, t2, sort_in

	addi t0, t0, 1
	blt t0, t2, sort
	jr x1


	

