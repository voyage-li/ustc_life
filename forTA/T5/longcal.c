#include <malloc.h>
#include <stdio.h>
#include <string.h>

int readlongint(char *x);
char *addition(char *x, char *y);
char *multiplacation(char *x, char *y);
void outputlongint(char *x);

int main()
{
    printf("请输入a和b:\n");
    char *a = (char *)malloc(sizeof(char) * 256);
    char *b = (char *)malloc(sizeof(char) * 256);
    memset(a, 0, sizeof(char) * 256);
    memset(b, 0, sizeof(char) * 256);
    readlongint(a);
    readlongint(b);
    char *add = addition(a, b);
    printf("a+b: ");
    outputlongint(add);
    free(add);
    char *mul = multiplacation(a, b);
    printf("a*b: ");
    outputlongint(mul);
    free(a);
    free(b);
    free(mul);
    return 0;
}

void Reverse(char *word)
{
    char temp;
    int i, j;
    for (j = 0, i = strlen(word) - 1; j < i; --i, ++j)
    {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
}

int readlongint(char *x)
{
    int index = 0;
    char c = '\0';
    int flag = 0;
    while (1)
    {
        index = 0;
        flag = 0;
        while ((c = getchar()) != '\n')
        {
            if (c <= '9' && c >= '0')
                *(x + index++) = c;
            else
                flag = 1;
        }
        if (flag == 0)
        {
            *(x + index) = '\0';
            break;
        }
        else
            printf("重新输入！\n");
    }
    Reverse(x);
    return index;
}

char *addition(char *x, char *y)
{
    int l1 = strlen(x);
    int l2 = strlen(y);
    int ans_len = (l1 > l2) ? l1 + 1 : l2 + 1;
    char *ans = (char *)malloc(sizeof(char) * (ans_len));
    memset(ans, 0, sizeof(char) * ans_len);
    int flag = 0;
    int temp;
    for (int i = 0; i < ans_len; i++)
    {
        temp = flag;
        if (i < l1)
            temp += *(x + i) - '0';
        if (i < l2)
            temp += *(y + i) - '0';
        flag = temp / 10;
        *(ans + i) = temp % 10 + '0';
    }
    if (temp == 0)
        *(ans + ans_len - 1) = '\0';
    else
        *(ans + ans_len) = '\0';
    return ans;
}

char *multiplacation(char *x, char *y)
{
    int l1 = strlen(x);
    int l2 = strlen(y);
    char data[l2][l1 + l2];
    int temp = 0;
    int flag = 0;
    for (int i = 0; i < l2; i++)
        for (int j = 0; j < l1 + l2; j++)
            data[i][j] = '0';
    for (int i = 0; i < l2; i++)
    {
        temp = flag = 0;
        for (int j = 0; j < l1; j++)
        {
            temp = (*(x + j) - '0') * (*(y + i) - '0') + flag;
            flag = temp / 10;
            temp = temp % 10;
            data[i][i + j] = temp + '0';
        }
        data[i][i + l1] = flag + '0';
        if (data[i][i + l1] == '0')
            data[i][i + l1] = '\0';
        else
            data[i][i + l1 + 1] = '\0';
    }
    char *ans = (char *)malloc(sizeof(char) * (l1 + l2));
    memset(ans, 0, sizeof(char) * (l1 + l2));
    for (int i = 0; i < l2; i++)
        ans = addition(ans, data[i]);
    return ans;
}

void outputlongint(char *x)
{
    Reverse(x);
    printf("%s\n", x);
    Reverse(x);
}