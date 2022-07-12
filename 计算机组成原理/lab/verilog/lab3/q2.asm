.data
testlw:		.word	10, 15
testsw:		.word	0
testbeq: 	.word   0
testjal:	.word   0

.text
main:
    la a1, testlw
    lw a2, 4(a1)
    addi a2, x0, 5
    sw a2, 0(a1)
    add a2, a2, a2
    sw a2, 0(a1)
    add t0, x0, a2
    addi t1, x0, 7
    beq t0, a2, next
    addi t1, t1, 7
next:
    jal test
    li a7, 10
    ecall
test:
    la a1, testjal
    addi t1, t1, 7
    sw t1, 0(a1)
    jr x1

