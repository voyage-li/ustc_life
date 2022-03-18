#!/bin/bash

make clean

make

if [ $status -ne 0 ]
	echo "make failed"
else
	echo "make succeed"
	qemu-system-i386 -kernel output/myOS.elf -serial stdio
end
