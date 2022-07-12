.globl start

MAGIC_ITEM_NAME=0x1badb002
FLAGS_ITEM_NAME=0x0
CHECKSUM_ITEM_NAME=0xe4524ffe

.section ".multiboot_header"

.long MAGIC_ITEM_NAME
.long FLAGS_ITEM_NAME
.long CHECKSUM_ITEM_NAME

.text
.code32

start:
	/*VGA*/
	movl $0x2f652f48, 0xb8000
	movl $0x2f6c2f6c, 0xb8004
	movl $0x2f202f6f, 0xb8008
	movl $0x2f6f2f77, 0xb800c
	movl $0x2f6c2f72, 0xb8010
	movl $0x2f202f64, 0xb8014
	movl $0x2f422f50, 0xb8018
	movl $0x2f302f32, 0xb801c
	movl $0x2f302f30, 0xb8020
	movl $0x2f312f30, 0xb8024
	movl $0x2f372f33, 0xb8028
	movl $0x2f6c2f5f, 0xb802c
	movl $0x2f682f79, 0xb8030

	/*串口*/
	movb $0x48, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x65, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x6c, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x6c, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x6f, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x20, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x77, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x6f, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x72, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x6c, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x64, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x20, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x50, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x42, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x32, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x30, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x30, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x30, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x30, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x31, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x33, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x37, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x5f, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x6c, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x79, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop
	movb $0x68, %al
	movw $0x3F8, %dx
	outb %al, %dx
	nop

	hlt
