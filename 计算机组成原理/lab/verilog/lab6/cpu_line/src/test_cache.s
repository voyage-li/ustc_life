.text
    addi x1, x0, 10
    sw x1, 0x300(x0)
    andi x2, x0, 15
    sw x2, 0x304(x0)
    ori x3, x0, 20
    sw x3, 0x308(x0)
    nop
    nop
    nop
    nop
    nop
    lw x1, 0x308(x0)
    nop
    lw x2, 0x304(x0)
    nop
    lw x3, 0x300(x0)
    nop