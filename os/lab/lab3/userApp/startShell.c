#include "i8253.h"
#include "i8259A.h"
#include "io.h"
#include "myPrintk.h"
#include "tick.h"
#include "uart.h"
#include "vga.h"
#include "wallClock.h"

typedef struct myCommand
{
    char name[80];
    char help_content[200];
    int (*func)(int argc, char (*argv)[8]);
} myCommand;

int func_cmd(int argc, char (*argv)[8]);
int func_help(int argc, char (*argv)[8]);
int func_clear(int argc, char (*argv)[8]);

myCommand cmd = {"cmd\0", "List all command", func_cmd};
myCommand help = {"help\0", "Usage: help [command]\nDisplay info about [command]", func_help};
myCommand clear = {"clear\0", "clear the screen", func_clear};

int func_cmd(int argc, char (*argv)[8])
{
    myPrintk(0x7, "1.  ");
    myPrintk(0x7, cmd.name);
    myPrintk(0x7, "\n");
    myPrintk(0x7, "2.  ");
    myPrintk(0x7, help.name);
    myPrintk(0x7, "\n");
    myPrintk(0x7, "3.  ");
    myPrintk(0x7, clear.name);
    myPrintk(0x7, "\n");
}

int judge_command(char *str)
{
    if (str[0] == 'c' && str[1] == 'm' && str[2] == 'd' && str[3] == '\0')
        return 1;
    if (str[0] == 'h' && str[1] == 'e' && str[2] == 'l' && str[3] == 'p' && str[4] == '\0')
        return 2;
    if (str[0] == 'c' && str[1] == 'l' && str[2] == 'e' && str[3] == 'a' && str[4] == 'r' && str[5] == '\0')
        return 3;
    return 0;
}

int func_help(int argc, char (*argv)[8])
{
    if (argc == 1)
        myPrintk(0x7, help.help_content);
    else
    {
        if (judge_command(argv[1]) == 1)
            myPrintk(0x7, cmd.help_content);
        else if (judge_command(argv[1]) == 2)
            myPrintk(0x7, help.help_content);
        else if (judge_command(argv[1]) == 3)
            myPrintk(0x7, clear.help_content);
        else
            myPrintk(0x7, "No Such Command please use cmd to see more information");
    }
    myPrintk(0x7, "\n");
}

int func_clear(int argc, char (*argv)[8])
{
    clear_screen();
}

int split(char *str, char (*argv)[8], int len)
{
    int iter = 0;
    int num = 0;
    int i = 0;
    while (iter < len)
    {
        if (str[iter] != ' ')
        {
            argv[num][i] = str[iter];
            i++;
            iter++;
        }
        else
        {
            argv[num][i] = '\0';
            num++;
            i = 0;
            iter++;
        }
    }
    argv[num][i] = '\0';
    num++;
    return num;
}

void startShell(void)
{
    //我们通过串口来实现数据的输入
    char BUF[256];   //输入缓存区
    int BUF_len = 0; //输入缓存区的长度

    int argc;
    char argv[8][8];

    do
    {
        BUF_len = 0;
        myPrintk(0xa, "voyage@qemu\0");
        myPrintk(0x7, "$ ");
        char str_for_out[2];
        str_for_out[1] = '\0';

        while ((BUF[BUF_len] = uart_get_char()) != '\r')
        {
            if (BUF[BUF_len] == 127)
            {
                myPrintk(0x7, "\b \b");
                BUF_len--;
                continue;
            }
            uart_put_char(BUF[BUF_len]); //将串口输入的数存入BUF数组中
            str_for_out[0] = BUF[BUF_len];
            myPrintk_only_vga(0x7, str_for_out);
            myPrintk_only_vga(0x7, "%d", BUF[BUF_len]);
            BUF_len++; // BUF数组的长度加
        }
        BUF[BUF_len] = '\0';
        uart_put_chars(" -pseudo_terminal\0");

        myPrintk(0x7, "\n");
        // OK,助教已经帮助你们实现了“从串口中读取数据存储到BUF数组中”的任务，接下来你们要做
        //的就是对BUF数组中存储的数据进行处理(也即，从BUF数组中提取相应的argc和argv参
        //数)，再根据argc和argv，寻找相应的myCommand ***实例，进行***.func(argc,argv)函数
        //调用。

        //比如BUF中的内容为 “help cmd”
        //那么此时的argc为2 argv[0]为help argv[1]为cmd
        //接下来就是 help.func(argc, argv)进行函数调用即可
        argc = split(BUF, argv, BUF_len);
        if (judge_command(argv[0]) == 1)
            func_cmd(argc, argv);
        else if (judge_command(argv[0]) == 2)
            func_help(argc, argv);
        else if (judge_command(argv[0]) == 3)
            func_clear(argc, argv);
        else if (BUF[0] == '\0')
        {
        }
        else
            myPrintk(0x7, "Command %s not found!\n", BUF);

    } while (1);
}
