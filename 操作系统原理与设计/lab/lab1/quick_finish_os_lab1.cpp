#include <bits/stdc++.h>
int main()
{
    system("sudo apt install qemu-system-x86 -y");
    std::ofstream make_file("Makefile");
    make_file << "ASM_FLAGS= -m32 --pipe -Wall -fasm -g -O1 -fno-stack-protector\n\nmultibootHeader.bin: multibootHeader.S\n	gcc -c ${ASM_FLAGS} multibootHeader.S -o multibootHeader.o\n	ld -n -T multibootHeader.ld multibootHeader.o -o multibootHeader.bin\nclean:\n	rm -rf ./multibootHeader.bin ./multibootHeader.o\n";
    make_file.close();

    std::ofstream ld("multibootHeader.ld");
    ld << "OUTPUT_FORMAT(\"elf32-i386\", \"elf32-i386\", \"elf32-i386\")\nOUTPUT_ARCH(i386)\nENTRY(start)\n\nSECTIONS {\n    . = 1M;\n    .text : {\n        *(.multiboot_header)\n        . = ALIGN(8);\n        *(.text)\n    }\n}\n";
    ld.close();

    std::ofstream outfile("multibootHeader.S");
    outfile << ".globl start\n\nMAGIC_ITEM_NAME=0x1badb002\nFLAGS_ITEM_NAME=0x0\nCHECKSUM_ITEM_NAME=0xe4524ffe\n\n.section \".multiboot_header\"\n\n.long MAGIC_ITEM_NAME\n.long FLAGS_ITEM_NAME\n.long CHECKSUM_ITEM_NAME\n\n.text\n.code32\n\nstart:\n";
    std::cout << "input a string: ";
    std::string s;
    getline(std::cin, s);
    std::vector<int> data;
    for (auto iter : s)
        data.push_back((int)iter);
    int num = 0xb8000;
    for (int i = 0; i < data.size(); i += 2)
    {
        if (i + 1 < data.size())
            outfile << "\tmovl $0x2f" << std::hex << data[i + 1] << "2f" << std::hex << data[i] << ", 0x" << std::hex << num << std::endl;
        else
            outfile << "\tmovl $0x2f202f" << std::hex << data[i] << ", 0x" << std::hex << num << std::endl;
        num += 4;
    }
    outfile << "\n\tnop\n\n";
    for (int i = 0; i < data.size(); i += 1)
        outfile << "\tmovb $0x" << std::hex << data[i] << ", \%al\n\tmovw $0x3F8, \%dx\n\toutb \%al, \%dx\n\tnop" << std::endl;
    outfile << "\thlt" << std::endl;
    outfile.close();

    system("make clean && make");
    system("clear");
    system("qemu-system-i386 -kernel multibootHeader.bin -serial stdio");
    putchar('\n');
    system("make clean");

    return 0;
}