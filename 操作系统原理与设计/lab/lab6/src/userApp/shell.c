// shell.c --- malloc version
#include "../myOS/userInterface.h"

#define NULL (void *)0

int getCmdline(unsigned char *buf, int limit)
{
    unsigned char *ptr = buf;
    int n = 0;
    while (n < limit)
    {
        *ptr = uart_get_char();
        if (*ptr == 0xd)
        {
            *ptr++ = '\n';
            *ptr = '\0';
            uart_put_char('\r');
            uart_put_char('\n');
            return n + 2;
        }
        uart_put_char(*ptr);
        ptr++;
        n++;
    }

    return n;
}

typedef struct cmd
{
    unsigned char cmd[20 + 1]; // TODO: dynamic
    int (*func)(int argc, unsigned char **argv);
    void (*help_func)(void);
    unsigned char description[100 + 1]; // TODO: dynamic?
    struct cmd *nextCmd;
} cmd;

int strlen(char *str)
{
    int len = 0;
    while (*(str + len) != '\0')
        len++;
    return len;
}

#define cmd_size sizeof(struct cmd)

struct cmd *ourCmds = NULL;

int listCmds(int argc, unsigned char **argv)
{
    struct cmd *tmpCmd = ourCmds;
    myPrintf(0x7, "list all registered commands:\n");
    myPrintf(0x7, "command name: description\n");

    while (tmpCmd != NULL)
    {
        myPrintf(0x7, "% 12s: %s\n", tmpCmd->cmd, tmpCmd->description);
        tmpCmd = tmpCmd->nextCmd;
    }
    return 0;
}

void update(unsigned char *s, unsigned char *p)
{
    int i = 0;
    while (1)
    {
        if (*(s + i) == '\0')
            break;
        *(p + i) = *(s + i);
        i++;
    }
    *(p + i) = '\0';
}

void addNewCmd(unsigned char *command,
               int (*func)(int argc, unsigned char **argv),
               void (*help_func)(void),
               unsigned char *description)
{
    //本函数需要实现！！！
    /*功能：增加命令
    1.使用malloc创建一个cmd的结构体，新增命令。
    2.同时还需要维护一个表头为ourCmds的链表。
    */
    struct cmd *newcmd = (struct cmd *)malloc(sizeof(struct cmd));
    newcmd->func = func;
    newcmd->help_func = help_func;
    update(command, newcmd->cmd);
    update(description, newcmd->description);

    // myPrintf(0x7, "ourCmds_addr: %d \n", (unsigned long)ourCmds);
    // myPrintf(0x7, "ourCmds: %s \n", ourCmds->cmd);
    // myPrintf(0x7, "newCmds_addr: %d \n", (unsigned long)newcmd);
    // myPrintf(0x7, "newCmds: %s \n", newcmd->cmd);
    newcmd->nextCmd = ourCmds;
    ourCmds = newcmd;
}

void help_help(void)
{
    myPrintf(0x7, "USAGE: help [cmd]\n\n");
}

int help(int argc, unsigned char **argv)
{
    // int i;
    // struct cmd *tmpCmd = ourCmds;
    // help_help();

    // if (argc == 1)
    //     return listCmds(argc, argv);
    // if (argc > 2)
    //     return 1;

    // while (tmpCmd != NULL)
    // {
    //     if (strcmp(argv[1], tmpCmd->cmd) == 0)
    //     {
    //         if (tmpCmd->help_func != NULL)
    //             tmpCmd->help_func();
    //         else
    //             myPrintf(0x7, "%s\n", tmpCmd->description);
    //         break;
    //     }
    //     tmpCmd = tmpCmd->nextCmd;
    // }
    int loc = 0x0061FE00;
    for (int i = 0; i < 12; i++)
        *(unsigned *)(loc + i) = i;
    char(*a)[4] = loc;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            myPrintf(0x7, "%2d ", a[i][j]);
        myPrintf(0x7, "\n");
    }
    char *p = *a;
    char(*q)[4] = a;

    return 0;
}

int clear(int argc, unsigned char **argv)
{
    clear_the_screen();
}

struct cmd *findCmd(unsigned char *cmd)
{
    struct cmd *tmpCmd = ourCmds;
    int found = 0;
    while (tmpCmd != NULL)
    { // at lease 2 cmds
        if (strcmp(cmd, tmpCmd->cmd) == 0)
        {
            found = 1;
            break;
        }
        tmpCmd = tmpCmd->nextCmd;
    }
    return found ? tmpCmd : NULL;
}

int split2Words(unsigned char *cmdline, unsigned char **argv, int limit)
{
    unsigned char c, *ptr = cmdline;
    int argc = 0;
    int inAWord = 0;

    while (c = *ptr)
    { // not '\0'
        if (argc >= limit)
        {
            myPrintf(0x7, "cmdline is tooooo long\n");
            break;
        }
        switch (c)
        {
        case ' ':
            *ptr = '\0';
            inAWord = 0;
            break; // skip white space
        case '\n':
            *ptr = '\0';
            inAWord = 0;
            break; // end of cmdline?
        default:   // a word
            if (!inAWord)
                *(argv + argc++) = ptr;
            inAWord = 1;
            break;
        }
        ptr++;
    }
    return argc;
}

int exit_num = 0;

int exit_shell(int argc, unsigned char **argv)
{
    myPrintf(0x6, "Exit the Shell\n");
    exit_num = 1;
}

void initShell(void)
{
    addNewCmd("cmd\0", listCmds, NULL, "list all registered commands\0");
    addNewCmd("help\0", help, help_help, "help [cmd]\0");
    addNewCmd("clear\0", clear, NULL, "clear the vga screen\0");
    addNewCmd("exit\0", exit_shell, NULL, "exit shell\0");
    // TODO: may be we can add a new command exit or quit
}

unsigned char cmdline[256]; //输入缓存区
void startShell(void)
{
    unsigned char *argv[10]; // max 10
    int argc;
    struct cmd *tmpCmd;
    // myPrintf(0x7,"StartShell:\n");

    int BUF_len = 0; //输入缓存区的长度

    while (!exit_num)
    {
        myPrintk_only_vga(0xa, "voyage@qemu");
        myPrintk_only_vga(0xf, "$ ");
        uart_put_chars("\e[32;1mvoyage@qemu\e[0m\e[1m$ \e[0m");

        char str_for_out[2];
        str_for_out[1] = '\0';
        BUF_len = 0;
        while ((cmdline[BUF_len] = uart_get_char()) != '\r')
        {
            if (cmdline[BUF_len] == 127 && BUF_len == 0)
            {
                continue;
            }
            else if (cmdline[BUF_len] == 127)
            {
                myPrintf(0x7, "\b \b");
                BUF_len--;
                continue;
            }
            uart_put_char(cmdline[BUF_len]); //将串口输入的数存入BUF数组中
            str_for_out[0] = cmdline[BUF_len];
            myPrintk_only_vga(0x7, str_for_out);
            BUF_len++; // BUF数组的长度加
        }
        cmdline[BUF_len] = '\0';
        myPrintf(0x7, "\n");

        // getCmdline(&cmdline[0], 100);

        argc = split2Words(cmdline, &argv[0], 10);
        if (argc == 0)
            continue;

        tmpCmd = findCmd(argv[0]);
        if (tmpCmd)
            tmpCmd->func(argc, argv);
        else
            myPrintf(0x7, "UNKOWN command: %s\n", argv[0]);
    }
}
