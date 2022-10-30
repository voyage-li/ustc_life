#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
int main()
{
    char str[MAXSIZE];
    char ch;
    int len;
    for (int i = 0; i < 3; i++)
    {
        printf("输入一个字符串：");
        scanf("%s", str);
        len = strlen(str);

        for (int j = 0; j < len; j++)
            if (str[j] >= '0' && str[j] <= '9')
                str[j] = '*';

        printf("正序：%s\n", str);
        for (int j = 0; j < len / 2; j++)
        {
            ch = str[j];
            str[j] = str[len - 1 - j];
            str[len - 1 - j] = ch;
        }
        printf("逆序：%s\n\n", str);
    }
    return 0;
}
