.data

first:      .word       1
second:     .word       2
goal:       .word       20
outans:     .word       0

.text
main:
    la a1, first
    lw a1, 0(a1)
    la a2, second
    lw a2, 0(a2)
    la t1, goal
    lw t1, 0(t1)
    addi t2, x0, 1

loop:
    beq t2, t1, exit
    add t3, a1, a2
    add a1, x0, a2
    add a2, x0, t3
    addi t2, t2, 1
    jal loop


exit:
    la t3, outans
    sw a1, 0(t3)
    addi a0, a1, 0
    li a7, 1
    ecall
    li a7 10
    ecall
