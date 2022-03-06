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
	movl $0x2f652f72, 0xb8000
	movl $0x2f712f77, 0xb8004
	movl $0x2f722f79, 0xb8008
	movl $0x2f692f75, 0xb800c
	movl $0x2f712f77, 0xb8010
	movl $0x2f792f6f, 0xb8014
	movl $0x2f652f72, 0xb8018
	movl $0x2f672f66, 0xb801c
	movl $0x2f6b2f61, 0xb8020
	movl $0x2f662f64, 0xb8024

	nop

	movb $0x72, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x65, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x77, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x71, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x79, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x72, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x75, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x69, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x77, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x71, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x6f, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x79, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x72, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x65, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x66, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x67, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x61, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x6b, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x64, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	movb $0x66, %al
movw $0x3F8, %dx
outb %al, %dx
nop
	hlt
